%{
# include <stdio.h>
# define YYDEBUG 1
#include "csua.h"
int yylex(void);
int yyerror(const char *s);
%}
%union{
    int iv;
    double dv;
    char *name;
    Expression* expression;
    AssignmentOperator aope;
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

%token <iv> INT_LITERAL
%token <dv> DOUBLE_LITERAL
%token <name> IDENTIFIER


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

%type <expression> expression assignment_expression logical_or_expression
                 logical_and_expression equality_expression relational_expression
                 additive_expression multiplicative_expression unary_expression
                 postfix_expression primary_expression
%type <aope> assignment_operator

%%
translation_unit
  : statement_list
  ;

statement_list
  : statement
  | statement_list statement
  ;

statement
/*: IDENTIFIER LPAREN RPAREN SEMICOLON */
  : expression SEMICOLON 
  {
    CS_Compiler* compiler = cs_get_current_compiler();
    compiler->expr_list = cs_chain_expression_list(compiler->expr_list, $1);
  }
  ;

expression
  : assignment_expression
  {
  Expression* expr = $1;
  printf("type = %d\n", expr->kind);
  $$ = $1;
  }
  ;

assignment_expression
  : logical_or_expression
  | postfix_expression assignment_operator assignment_expression { $$ = cs_create_assignment_expression($1, $2, $3); }
  ;
assignment_operator
  : ASSIGN { $$ = CS_ASSIGN; }
  | ADD_ASSIGN { $$ = CS_ADD_ASSIGN; }
  | SUB_ASSIGN { $$ = CS_SUB_ASSIGN; }
  | MUL_ASSIGN { $$ = CS_MUL_ASSIGN; }
  | DIV_ASSIGN { $$ = CS_DIV_ASSIGN; }
  | MOD_ASSIGN { $$ = CS_MOD_ASSIGN; }
  ;

logical_or_expression
  : logical_and_expression
  | logical_or_expression OR logical_and_expression { printf("OR\n"); $$ = cs_create_binaly_expression(LOGICAL_OR_EXPRESSION, $1, $3); }
  ;
logical_and_expression
  : equality_expression
  | logical_and_expression AND equality_expression { printf("AND\n"); $$ = cs_create_binaly_expression(LOGICAL_AND_EXPRESSION, $1, $3); }
  ;

equality_expression
  : relational_expression
  | equality_expression EQ relational_expression { printf("EQ\n"); $$ = cs_create_binaly_expression(EQ_EXPRESSION, $1, $3); }
  | equality_expression NE relational_expression { printf("NE\n"); $$ = cs_create_binaly_expression(NE_EXPRESSION, $1, $3); }
  ;

relational_expression
  : additive_expression
  | relational_expression GT additive_expression { printf("gt\n"); $$ = cs_create_binaly_expression(GT_EXPRESSION, $1, $3); }
  | relational_expression GE additive_expression { printf("ge\n"); $$ = cs_create_binaly_expression(GE_EXPRESSION, $1, $3); }
  | relational_expression LE additive_expression { printf("le\n"); $$ = cs_create_binaly_expression(LE_EXPRESSION, $1, $3); }
  | relational_expression LT additive_expression { printf("lt\n"); $$ = cs_create_binaly_expression(LT_EXPRESSION, $1, $3); }
  ;

additive_expression
  : multiplicative_expression
  | additive_expression ADD multiplicative_expression { printf("add\n"); $$ = cs_create_binaly_expression(ADD_EXPRESSION, $1, $3); }
  | additive_expression SUB multiplicative_expression { printf("sub\n"); $$ = cs_create_binaly_expression(SUB_EXPRESSION, $1, $3); }
  ;

multiplicative_expression
  : unary_expression
  | multiplicative_expression MUL unary_expression { printf("mul\n"); $$ = cs_create_binaly_expression(MUL_EXPRESSION, $1, $3); }
  | multiplicative_expression DIV unary_expression  {printf("div\n"); $$ = cs_create_binaly_expression(DIV_EXPRESSION, $1, $3); }
  | multiplicative_expression MOD unary_expression { printf("mod\n"); $$ = cs_create_binaly_expression(MOD_EXPRESSION, $1, $3); }
  ;

unary_expression
  : postfix_expression
  | SUB unary_expression { $$ = cs_create_minus_expression($2); }
  | NOT unary_expression { $$ = cs_create_logical_not_expression($2); }
  ;

postfix_expression
  : primary_expression
  | postfix_expression LPAREN RPAREN { $$ = cs_create_function_call_expression($1, NULL); }
  | postfix_expression INCREMENT { $$ = cs_create_inc_dec_expression($1, INCREMENT_EXPRESSION); }
  | postfix_expression DECREMENT { $$ = cs_create_inc_dec_expression($1, DECREMENT_EXPRESSION); }
  ;

primary_expression
  : LPAREN expression RPAREN { $$ = $2; }
  | IDENTIFIER { $$ = cs_create_identifier_expression($1); }
  | INT_LITERAL { $$ = cs_create_int_expression($1); }
  | DOUBLE_LITERAL { $$ = cs_create_double_expression($1); }
  | TRUE {printf("TRUE\n"); $$ = cs_create_boolean_expression(CS_TRUE);}
  | FALSE {printf("FALSE\n"); $$ = cs_create_boolean_expression(CS_FALSE);}
  ;

%%
int
yyerror(char const *str)
{
    extern char *yytext;
    fprintf(stderr, "parser error near %s\n", yytext);
    return 0;
}

