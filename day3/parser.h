#ifndef PARSER_H_
#define PARSER_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum{
  VALUE,
  PLUS,
  MINUS,
  TIMES,
  DIVIDE,
  RIGHT,
  LEFT,
  END
} Kind;

typedef struct{
  int value;
  Kind kind;
  int read_pos;
} Token;

int expr(char *e, int counter, int depth);
int term(char *e, int counter, int depth);
int factor(char *e, int counter, int depth);

#endif