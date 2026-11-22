#ifndef CSUA_H_
#define CSUA_H_

#include "MEM.h"
#include <stdio.h>

typedef struct Expression_tag Expression;
typedef struct CS_Compiler_tag CS_Compiler;

typedef enum { CS_FALSE = 0, CS_TRUE = 1 } CS_Boolean;

typedef enum {
  BOOLEAN_EXPRESSION = 1,
  DOUBLE_EXPRESSION,        // 2
  INT_EXPRESSION,           // 3
  IDENTIFIER_EXPRESSION,    // 4
  INCREMENT_EXPRESSION,     // 5
  DECREMENT_EXPRESSION,     // 6
  FUNCTION_CALL_EXPRESSION, // 7
  MINUS_EXPRESSION,         // 8
  LOGICAL_NOT_EXPRESSION,   // 9
  MUL_EXPRESSION,           // 10
  DIV_EXPRESSION,
  MOD_EXPRESSION,
  ADD_EXPRESSION,
  SUB_EXPRESSION,
  GT_EXPRESSION,
  GE_EXPRESSION,
  LT_EXPRESSION,
  LE_EXPRESSION,
  EQ_EXPRESSION,
  NE_EXPRESSION,
  LOGICAL_AND_EXPRESSION,
  LOGICAL_OR_EXPRESSION,
  ASSIGN_EXPRESSION,
  EXPRESSION_KIND_PLUS_ONE
} ExpressionKind;

typedef struct {
  Expression *function;
} FunctionCallExpression;

typedef struct {
  char *name;
} IdentifierExpression;

typedef struct {
  Expression *left;
  Expression *right;
} BinaryExpression;

typedef enum {
  CS_ASSIGN = 1,
  CS_ADD_ASSIGN,
  CS_SUB_ASSIGN,
  CS_MUL_ASSIGN,
  CS_DIV_ASSIGN,
  CS_MOD_ASSIGN,
  CS_ASSIGN_PLUS_ONE
} AssignmentOperator;

typedef struct {
  AssignmentOperator aope;
  Expression *left;
  Expression *right;
} AssignmentExpression;

typedef struct ExpressionList_tag {
  Expression *expression;
  struct ExpressionList_tag *next;
} ExpressionList;

struct CS_Compiler_tag {
  MEM_Storage storage;
  ExpressionList *expr_list;
};

struct Expression_tag {
  ExpressionKind kind;
  union {
    double double_value;
    int int_value;
    CS_Boolean boolean_value;
    IdentifierExpression identifier;
    Expression *inc_dec;
    FunctionCallExpression function_call_expression;
    Expression *minus_expression;
    Expression *logical_not_expression;
    BinaryExpression binary_expression;
    AssignmentExpression assignment_expression;
  } u;
};

/* create.c */
void delete_storage();
Expression *cs_create_double_expression(double v);
Expression *cs_create_int_expression(int val);
Expression *cs_create_identifier_expression(char *identifier);
Expression *cs_create_inc_dec_expression(Expression *id_expr,
                                         ExpressionKind inc_dec);
Expression *cs_create_function_call_expression(Expression *function,
                                               void *args);
Expression *cs_create_minus_expression(Expression *operand);
Expression *cs_create_logical_not_expression(Expression *operand);
Expression *cs_create_boolean_expression(CS_Boolean boolean_value);
Expression *cs_create_binaly_expression(ExpressionKind kind, Expression *left,
                                        Expression *right);
Expression *cs_create_assignment_expression(Expression *left,
                                            AssignmentOperator aope,
                                            Expression *operand);
char *cs_create_identifier(const char *str);
ExpressionList *cs_chain_expression_list(ExpressionList *list,
                                         Expression *expr);

// interface.c
CS_Compiler *CS_create_compiler();
void CS_delete_compiler(CS_Compiler *compiler);
void CS_compile(CS_Compiler *compiler, FILE *fin);

// util.c
void cs_set_current_compiler(CS_Compiler *compiler);
CS_Compiler *cs_get_current_compiler();
#endif
