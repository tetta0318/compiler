#ifndef YYLEX_H_
#define YYLEX_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "id1.h"
#include "y.tab.h"

#define BUF_SIZE 1024

/*
#define ADD 43 // +
#define SUB 45 // -
#define MUL 42 // *
#define DIV 47 // /
#define MOD 37 // %
#define BIT_AND 38 // &
#define BIT_OR 124 // |
#define ASSIGN 61 // =
#define NOT 33 // !
#define GT 62 // >
#define LT 60 // <
#define LPAREN 40 // (
#define RPAREN 41 // )
#define LBRACE 123 // {
#define RBRACE 124 // }
#define CR 13 // \n
#define SPACE 32 
#define SEMICOLON 59 // ;
#define ENDOFFILE 150
#define AND 3838 // $$
#define OR 124124 // ||
#define NE 3361 // !=
#define EQ 6161 // ==
#define GE 6261 // >=
#define LE 6061 // <=
#define ADD_ASSIGN 4361 // +=
#define SUB_ASSIGN 4561 // -=
#define MUL_ASSIGN 4261 // *=
#define DIV_ASSIGN 4761 // /=
#define INT_LITERAL 1
#define INT_T 128
#define DOUBLE_T 129
#define STRING_T 130
#define IF 131
#define ELSE 132
#define ELSIF 133
#define WHILE 134
#define FOR 135
#define RETURN 136
#define BREAK 137
#define CONTINUE 138
#define TRUE 139
#define FALSE 140
#define BOOLEAN_T 141
#define IDENTIFER 142

*/

typedef struct buffer_state{
  FILE *input_file;

  char ch_buf[BUF_SIZE + 2];
  char *buf_pos;

  int has_next;
} BUFFER_STATE;

/*
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
  char *name;
  double dv;
  int int_value;
} YYSTYPE;
*/

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