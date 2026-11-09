#ifndef YYLEX_H_
#define YYLEX_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "id1.h"

#define BUF_SIZE 1024

typedef struct buffer_state{
  FILE *input_file;

  char ch_buf[BUF_SIZE + 2];
  char *buf_pos;

  int has_next;
} BUFFER_STATE;

typedef enum yytokentype {
    INT_VALUE,
    INT = 128,
    DOUBLE = 129,
    STRING = 130,
    IF = 131,
    ELSE = 132,
    ELSIF = 133,
    WHILE = 134,
    FOR = 135,
    RETURN = 136,
    BREAK = 137,
    CONTINUE = 138,
    TRUE = 139,
    FALSE = 140,
    BOOLEAN = 141,
    IDENTIFER,
    ADD,        // +
    SUB,        // -
    MUL,        // *
    DIV,        // /
    MOD,        // %
    BIT_AND,    // &
    BIT_OR,     // |
    ASSIGN,     // =
    AND,        // &&
    OR,         // ||
    NOT,        // !
    GT,         // >
    LT,         // <
    NE,         // !=
    EQ,         // ==
    GE,         // >=
    LE,         // <=
    MUL_ASSIGN, // *=
    DIV_ASSIGN, // /=
    ADD_ASSIGN, // +=
    SUB_ASSIGN, // -=

    LPAREN,     // (
    RPAREN,     // )
    LBRACE,     // {
    RBRACE,     // }
    CR,
    SEMICOLON,  // ;
    SPACE,
    ENDOFFILE
} yytokentype;

typedef union{
  char *identifer_name;
  double double_value;
  int int_value;
} YYSTYPE;

typedef enum{
  START,
  VALUE,
  ZERO,
  PLUS,
  MINUS,
  TIMES,
  DIVISION,
  MODULO,
  AMPERSAND,
  PIPE,
  EQUAL,
  EXCLAMATION,
  GREATER,
  LESS,
  CHAR,
  OPERATER,
  RESERVED_WORD,
  SYMBOL,
  END_OF_FILE,
  END,
  DEFAULT
} STATE;

int yylex();
extern struct RESERVED_WORD * in_word_set(const char*, unsigned int);
extern YYSTYPE yylval;

static BUFFER_STATE * buffer_state = NULL;

#endif