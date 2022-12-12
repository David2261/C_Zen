#ifndef SRC_COMMON_MAIN_H_
#define SRC_COMMON_MAIN_H_
#define _GNU_SOURCE 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
  int flag_b;
  int flag_e;
  int flag_v;
  int flag_n;
  int flag_s;
  int flag_t;
  int flag_T;
  int flag_E;
} Option;

typedef struct
{
  int flag_e;
  int flag_i;
  int flag_v;
  int flag_c;
  int flag_l;
  int flag_n;
  int flag_h;
  int flag_s;
  int flag_f;
  int flag_o;
} Option_2;

int checker(char *, char);

#endif // SRC_COMMON_MAIN_H_