#include "s21_grep.h"

// grep [options] [regexp] [filename]
#define BUFF 1024

int _count_files(char *file_name[]) {
  int count = 0;
  while (*file_name++) ++count;
  return count;
}

int main(int argc, char *argv[]) {
  Option_2 opt;
  init_str(&opt);

  int FLAG = 0;
  int e_f = 0;
  char *file[BUFF] = {NULL};
  char *template[BUFF] = {NULL};

  if (argc >= 3) {
    // Заполнение массивов
    read_set(argc, argv, file, template, &opt);
  } else {
    FLAG = 1;
  }
  // Для проверки на наличие файла
  if (!*file) FLAG = 1;
  // Работа с шаблоном
  if (!FLAG) {
    if (*template == NULL) {
      e_f = 1;
      // int ch = strlen(*file);
      // *template = malloc(sizeof(char*) * ch + 1);
      *template = malloc(sizeof(char *) * (strlen(*file) + 1));
      if (*template == NULL) {
        FLAG = 1;
      } else {
        strcpy(*template, *file);
      }
    }

    // Считывает количество файлов
    int count_file = _count_files(file) - e_f;

    for (int i = e_f; file[i] && FLAG == 0; i++)
      FLAG = grep(&opt, file[i], template, count_file);
    for (int i = 0; file[i]; i++) free(file[i]);
    for (int i = 0; template[i]; i++) free(template[i]);
  }
  if (FLAG == 1) printf("n/a");

  return FLAG;
}

int init_str(Option_2 *opt) {
  opt->flag_e = 0;
  opt->flag_i = 0;
  opt->flag_v = 0;
  opt->flag_c = 0;
  opt->flag_l = 0;
  opt->flag_n = 0;
  opt->flag_h = 0;
  opt->flag_s = 0;
  opt->flag_f = 0;
  opt->flag_o = 0;
  return 0;
}

int read_set(int argc, char **argv, char **file, char **template,
             Option_2 *opt) {
  int FLAG = 0, y = 0, j = 0, check = 0;

  // Проверка на валидность флагов
  for (int i = 1; i < argc; i++)
    if (strlen(*argv) == strspn(*argv, "-eivclnhsfo")) FLAG = 1;

  if (FLAG == 0) {
    for (int i = 1; i < argc; i++) {
      // Ошибка, идет сброс флагов и запись флага i = 4
      check = taker(argv[i], opt);
      if (check) {
        // Если -f или -e нет в массиве
        if ((opt->flag_e || opt->flag_f) && !argv[i]) {
          FLAG = 0;
          break;
        }
        if (opt->flag_e) {
          i++;
          template[j] = malloc(sizeof(char) * (strlen(argv[i]) + 1));
          if (template[j] == NULL) {
            FLAG = 1;
            break;
          }
          strcpy(template[j], argv[i]);
          ++j;
        } else if (opt->flag_f) {
          i++;
          // Для проверки флага -f
          if ((FLAG = regular_expression(argv[i], template, &j)) != 0) break;
        }
        // Сброс флагов
        opt->flag_e = 0;
        opt->flag_f = 0;
      } else {
        // int ch = strlen(argv[i]);
        // file[y] = malloc(sizeof(char) * ch + 1);
        file[y] = malloc(sizeof(char) * (strlen(argv[i]) + 1));
        if (!file[y]) {
          FLAG = 1;
          break;
        }
        strcpy(file[y], argv[i]);
        ++y;
      }
    }
  }
  template[j] = NULL;
  file[y] = NULL;
  // free(template[j]);
  // free(file[y]);
  return FLAG;
}

int taker(char *argv, Option_2 *opt) {
  // Функция, которая проверяет флаги
  int parametr = 0;
  (void)opt;
  if (argv[0] == '-') {
    for (int i = 1; argv[i]; i++) {
      if (strchr(argv, 'e')) opt->flag_e = 1;
      if (strchr(argv, 'i')) opt->flag_i = 1;
      if (strchr(argv, 'v')) opt->flag_v = 1;
      if (strchr(argv, 'c')) opt->flag_c = 1;
      if (strchr(argv, 'l')) opt->flag_l = 1;
      if (strchr(argv, 'n')) opt->flag_n = 1;
      if (strchr(argv, 'h')) opt->flag_h = 1;
      if (strchr(argv, 's')) opt->flag_s = 1;
      if (strchr(argv, 'f')) opt->flag_f = 1;
      if (strchr(argv, 'o')) opt->flag_o = 1;
    }
    parametr = 1;
  }
  return parametr;
}

int regular_expression(char *path, char *templates[], int *index) {
  int FLAG = 0;
  FILE *file = fopen(path, "r");
  if (!file) {
    FLAG = 1;
  } else {
    char *template = NULL;
    size_t stream_size = 0;          // Количество символов
    ssize_t stream_size_length = 0;  // Размер строки
    while (0 < (stream_size_length = getline(&template, &stream_size, file))) {
      templates[*index] = malloc(sizeof(char) * (stream_size_length + 1));
      if (!templates[*index]) {
        FLAG = 1;
        break;
      }
      // Запись
      strcpy(templates[*index], template);
      templates[*index][strcspn(templates[*index], "\r\n")] = '\0';

      // Если файл пустой с шаблоном
      if (!strlen(templates[*index])) templates[*index][0] = '.';
      (*index)++;
    }

    fclose(file);
    free(template);
  }
  return FLAG;
}

int grep(Option_2 *opt, char *path, char *template[], int count) {
  FILE *file = fopen(path, "r");
  int FLAG = 0;

  if (file != NULL) {
    int matched_lines = 0, count_line = 0;
    char *str = NULL;
    char *matches[BUFF] = {NULL};
    size_t stream_size = 0;

    // str = (char *)malloc(sizeof(char *) * BUFF);
    while (0 < getline(&str, &stream_size, file)) {
      count_line++;
      // Игнор регистра
      if (comparison(str, template, matches, opt)) {
        matched_lines++;
        if (!opt->flag_c && !opt->flag_l) {
          if (!opt->flag_c && !opt->flag_h && count > 1) printf("%s:", path);
          if (opt->flag_n) printf("%d:", count_line);
          if (opt->flag_o && !opt->flag_v) {
            for (int j = 0; matches[j]; j++) printf("%s\n", matches[j]);
          } else {
            if (str[strlen(str) - 1] == '\n') {
              printf("%s", str);
            } else {
              printf("%s\n", str);
            }
          }
        }
      }

      for (int j = 0; matches[j]; j++) free(matches[j]);
    }
    // Для флагов -c
    if (opt->flag_c && !opt->flag_h && 1 < count) printf("%s:", path);

    if (opt->flag_c)
      printf("%d\n", opt->flag_l ? matched_lines > 0 : matched_lines);
    if (opt->flag_l && matched_lines) printf("%s\n", path);
    free(str);
    fclose(file);
  } else if (!opt->flag_s) {
    FLAG = 1;
  }
  return FLAG;
}

int comparison(const char *const str, char **template, char **matches,
               const Option_2 *opt) {
  // Сравнение с шаблоном
  int index = 0;
  for (int i = 0; template[i]; i++) {
    regex_t regex;
    if (opt->flag_i) {
      // Игнор регистра
      regcomp(&regex, template[i], REG_ICASE);
    } else {
      regcomp(&regex, template[i], REG_EXTENDED);
    }
    regmatch_t match;
    size_t str_length = strlen(str);
    size_t reg_offset = 0;

    for (int reg = 0;
         (reg = regexec(&regex, str + reg_offset, 1, &match, 0)) == 0;
         index++) {
      size_t length = match.rm_eo - match.rm_so;

      // matches[index] = (char*)malloc(sizeof(char*) * (length + 1));
      matches[index] = (char *)malloc(sizeof(char) * length + 1);
      memcpy(matches[index], str + match.rm_so + reg_offset, length);
      matches[index][length] = '\0';
      reg_offset += match.rm_eo;
      if (reg_offset > str_length) break;
    }
    matches[index] = NULL;
    regfree(&regex);
  }
  return opt->flag_v ? !index : index;
}