#ifndef LEX_H_
#define LEX_H_

#include <stdlib.h>
#include "parser.h"

#define STR_LEN 

typedef enum{
  s0,
  s1,
  s2,
  s3,
  s4
} State;

Token *lex(char s[], int counter);

#endif