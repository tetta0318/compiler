%{
# include <stdio.h>
# define YYDEBUG 1
int yylex(void);
extern char yyerror(const char *s);
%}
%union{
    int iv;
    double dv;
    char *name;
}

%token LPAREN
%token RPAREN
%token LBRACE
%token RBRACE
%token COMMA
%token BIT_AND
%token BIT_OR
%token EQ
%token ASSIGN
%token NE
%token GT
%token GE
%token LE
%token LT
%token SEMICOLON
%token COLON
%token ADD
%token SUB
%token MUL
%token DIV
%token MOD
%token ADD_ASSIGN
%token SUB_ASSIGN
%token MUL_ASSIGN
%token DIV_ASSIGN
%token MOD_ASSIGN
%token INCREMENT
%token DECREMENT
%token NOT
%token DOT
%token AND
%token OR
%token CR
%token SPACE
%token ENDOFFILE

%token INT_LITERAL
%token DOUBLE_LITERAL
%token IDENTIFIER


%token IF
%token ELSE
%token ELSIF
%token WHILE
%token FOR
%token RETURN
%token BREAK
%token CONTINUE
%token TRUE
%token FALSE
%token BOOLEAN_T
%token INT_T
%token DOUBLE_T
%token STRING_T

%%
translation_unit
	: statement
	;
statement
	: IDENTIFIER LPAREN RPAREN SEMICOLON
	;
%%
int
yyerror(char const *str)
{
    extern char *yytext;
    fprintf(stderr, "parser error near %s\n", yytext);
    return 0;
}

