#include "s21_cat.h"

int main(int argc, char **argv)
{
  Option opt;
  int i = 0, FLAG = 0;
  init_flag(&opt);
  if (1 < argc)
  {
    while (i < argc)
    {
      if (argv[i][0] == '-' && argv[i][1] != '-')
      {
        opt.flag_s = checker(argv[i], 's');
        opt.flag_b = checker(argv[i], 'b');
        opt.flag_e = checker(argv[i], 'e');
        opt.flag_n = checker(argv[i], 'n');
        opt.flag_t = checker(argv[i], 't');
        opt.flag_T = checker(argv[i], 'T');
        opt.flag_E = checker(argv[i], 'E');
        if (opt.flag_t == 1)
          opt.flag_v = 1;
        if (opt.flag_e == 1)
          opt.flag_v = 1;
      }
      if (argv[i][0] == '-' && argv[i][1] == '-')
      {
        if (strcmp(argv[i], "--number") == 0)
          opt.flag_n = 1;
        if (strcmp(argv[i], "--number-nonblank") == 0)
          opt.flag_b = 1;
        if (strcmp(argv[i], "--squeeze-blank") == 0)
          opt.flag_s = 1;
      }
      i++;
    }
    if (opt.flag_b)
      opt.flag_n = 0;

    FLAG = read_file(argv, &opt);
  }
  else
  {
    FLAG = 1;
  }
  if (FLAG == 1)
    printf("n/a");
  return FLAG;
}

void init_flag(Option *opt)
{
  opt->flag_b = 0;
  opt->flag_e = 0;
  opt->flag_n = 0;
  opt->flag_s = 0;
  opt->flag_t = 0;
  opt->flag_v = 0;
}

int read_file(char **argv, Option *opt)
{
  FILE *file;
  argv++;
  int FLAG = 1;
  while (*argv)
  {
    if (*argv[0] == '-')
    {
      argv++;
    }
    else
    {
      if ((file = fopen(*argv, "r")) == NULL)
      {
        FLAG = 1;
        argv++;
      }
      else
      {
        FLAG = cat(opt, file);
        argv++;
      }
    }
  }
  // pclose(file);
  return FLAG;
}

int cat(Option *opt, FILE *file)
{

  int empty_line = 1;
  int count_line = 1;
  char prev = '\n';
  char next = ' ';
  char now[1024] = {'\0'};
  int start = 1, FLAG = 0;
  while (1)
  {
    // if ((now = getc(file)) == EOF)
    // {
    //   FLAG = 1;
    //   break;
    // }
    // if (opt->flag_s != 1 || prev != '\n' || now != '\n' || pp_sym != '\n')
    // {
    //   if ((prev == '\n') || ((temp == 1) && (opt->flag_n == 1 && opt->flag_b == 1)))
    //   {
    //     if ((opt->flag_n == 1 && opt->flag_b == 0) || (opt->flag_b == 1 && now != '\n'))
    //     {
    //       printf("%6d\t", temp);
    //       temp++;
    //     }
    //   }
    //   if (now == '\n')
    //   {
    //     if (opt->flag_e == 1)
    //       printf("$");
    //   }
    //   if (now == '\t' && opt->flag_t == 1)
    //   {
    //     printf("^I");
    //   }
    //   else if (now < 32 && opt->flag_v == 1 && now != 9 && now != 10)
    //   {
    //     printf("^%c", now + 64);
    //   }
    //   else
    //   {
    //     printf("%c", now);
    //   }
    // }
    if ((*now = getc(file)) == EOF)
    {
      FLAG = 1;
      break;
    }
    if (opt->flag_s != 1 && func_flag_s(prev, next, *now))
      continue;
    if (opt->flag_n)
      start = func_flag_n(start, &count_line, *now);
    if (opt->flag_b)
      func_flag_b(prev, &empty_line, *now);
    if (opt->flag_E)
      func_flag_E(*now);
    if (opt->flag_v)
      func_flag_v(now);
    next = prev;
    prev = *now;
    if (opt->flag_T && func_flag_T(*now))
      continue;
    if (*now == '\0')
      fputc(*now, stdout);
    else
      fputs(now, stdout);
    memset(now, '\0', 1024);
    fclose(file);
  }
  return FLAG;
}

int func_flag_s(char prev, char next, char now)
{
  return now == '\n' && prev == '\n' && next == '\n';
}

int func_flag_n(int start, int *count_line, char now)
{
  if (start)
    printf("%6d\t", (*count_line)++);
  return now == '\n';
}

int func_flag_b(char prev, int *empty_line, char now)
{
  if (prev == '\n' && now != '\n')
    printf("%6d\t", (*empty_line)++);
  return now == '\n';
}

int func_flag_E(char now)
{
  if (now == '\n')
    printf("$");
  return now == '\n';
}

int func_flag_v(char *now)
{
  unsigned char temp = *now; // 124
  if ((temp <= 8) || (temp >= 11 && temp <= 31) || (temp >= 127 && temp <= 159))
    strcpy(now, special_symbol[temp]);
  return temp;
}