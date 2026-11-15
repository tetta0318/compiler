#include "yylex.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
  extern int yylex(void);
  extern FILE *yyin;
  extern char yytext[];

  yyin = fopen("test.cs", "r");

  int kind;

  while ((kind = yylex()) != ENDOFFILE) {
    if (kind == INT_VALUE)
      printf("INT_LITERAL: %d\n", yylval.int_value);
    if (kind == ADD)
      printf("ADD\n");
    if (kind == SEMICOLON)
      printf("SEMICOLON:\n");
    if (kind == INT)
      printf("INT_T\n");
    if (kind == DOUBLE)
      printf("DOUBLE_T\n");
    if (kind == DOUBLE_VALUE)
      printf("DOUBLE_VALUE: %f\n", yylval.double_value);
    if (kind == STRING)
      printf("STRING_T\n");
    if (kind == IF)
      printf("IF\n");
    if (kind == ELSE)
      printf("ELSE\n");
    if (kind == ELSIF)
      printf("ELSIF\n");
    if (kind == WHILE)
      printf("WHILE\n");
    if (kind == FOR)
      printf("FOR\n");
    if (kind == RETURN)
      printf("RETURN\n");
    if (kind == BREAK)
      printf("BREAK\n");
    if (kind == CONTINUE)
      printf("CONTINUE\n");
    if (kind == TRUE)
      printf("TRUE\n");
    if (kind == FALSE)
      printf("FALSE\n");
    if (kind == BOOLEAN)
      printf("BOOLEAN_T\n");
    if (kind == IDENTIFER)
      printf("IDENTIFER -> %s\n", yylval.identifer_name);
    if (kind == DEFAULT)
      printf("default\n");
    if (kind == RPAREN)
      printf(")\n");
    if (kind == LPAREN)
      printf("(\n");
    if (kind == SPACE)
      printf("### SPACE tokenized ###\n");
    if (kind == CR)
      printf("### CR tokenized ###\n");
    if (kind == INCREMENT)
      printf("INCREMENT\n");
    if (kind == DECRIMENT)
      printf("DECRIMENT\n");
    if (kind == LBRACE)
      printf("{\n");
    if (kind == RBRACE)
      printf("}\n");
    if (kind == EQ)
      printf("==\n");
    if (kind == ASSIGN)
      printf("ASSIGN\n");
    if (kind == PARSE_ERROR) {
      printf("parse_error\n");
      return -1;
    }
    if (kind == GT)
      printf("<\n");
    if (kind == LT)
      printf(">\n");
  }
  printf("END OF FILE\n");
  fclose(yyin);
  return 0;
}
