%{
# include <stdio.h>
# define YYDEBUG 1
int yylex(void);
int yyerror(const char *s);
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
%token EQ //==
%token ASSIGN //=
%token NE //!=
%token GT //>
%token GE //>=
%token LE
%token LT
%token SEMICOLON
%token COLON
%token ADD
%token SUB
%token MUL
%token DIV
%token MOD
%token ADD_ASSIGN //+=
%token SUB_ASSIGN //-=
%token MUL_ASSIGN //*=
%token DIV_ASSIGN ///=
%token MOD_ASSIGN
%token INCREMENT
%token DECREMENT
%token NOT //!
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
/*: IDENTIFIER LP RP SEMICOLON */
  : expression SEMICOLON
  ;

expression
  : assignment_expression
  ;


assignment_expression
  : logical_or_expression
  | postfix_expression assignment_operator assignment_expression { printf("assign\n"); }
  ;
assignment_operator
  : ASSIGN { printf("=\n"); }
  | ADD_ASSIGN { printf("+=\n"); }
  | SUB_ASSIGN { printf("-=\n"); }
  | MUL_ASSIGN { printf("*=\n"); }
  | DIV_ASSIGN { printf("/=\n"); }
  | MOD_ASSIGN { printf("%% =\n"); }
  ;

logical_or_expression
  : logical_and_expression
  | logical_or_expression OR logical_and_expression { printf("LOR\n"); }
  ;
logical_and_expression
  : equality_expression
  | logical_and_expression AND equality_expression { printf("LAND\n"); }
  ;

equality_expression
  : relational_expression
  | equality_expression EQ relational_expression { printf("EQ\n"); }
  | equality_expression NE relational_expression { printf("NE\n"); }
  ;

relational_expression
  : additive_expression
  | relational_expression GT additive_expression { printf("gt\n"); }
  | relational_expression GE additive_expression { printf("ge\n"); }
  | relational_expression LT additive_expression { printf("lt\n"); }
  | relational_expression LE additive_expression { printf("le\n"); }
  ;

additive_expression
  : multiplicative_expression
  | additive_expression ADD multiplicative_expression { printf("ADD\n"); }
  | additive_expression SUB multiplicative_expression { printf("SUB\n"); }
  ;

multiplicative_expression
  : unary_expresion
  | multiplicative_expression MUL unary_expresion { printf("mul\n"); }
  | multiplicative_expression DIV unary_expresion { printf("div\n"); }
  | multiplicative_expression MOD unary_expresion { printf("mod\n"); }
  ;

unary_expresion
  : postfix_expression
  | SUB unary_expresion { printf("unary sub\n"); }
  | NOT unary_expresion { printf("unary exclamation\n"); }
  ;

postfix_expression
  : primary_expression
  | postfix_expression LPAREN RPAREN { printf("function call\n"); }
  | postfix_expression INCREMENT { printf("increment\n"); }
  | postfix_expression DECREMENT { printf("decrement\n"); }
  ;

primary_expression
  : LPAREN expression RPAREN { printf("LP expr RP\n"); }
  | IDENTIFIER { printf("IDENTIFIER\n"); }
  | INT_LITERAL { printf("INT_LITERAL\n"); }
  | DOUBLE_LITERAL { printf("DOUBLE_LITERAL\n"); }
  | TRUE { printf("TRUE\n"); }
  | FALSE { printf("FALSE\n"); }
  ;


%%

int
yyerror(char const *s)
{
    extern char *yytext;
    fprintf(stderr, "parser error near %s\n", yytext);
    return 0;
}

