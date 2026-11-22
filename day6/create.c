#include "MEM.h"
#include "csua.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static MEM_Storage storage;

static void init_storage() {
  if (storage == NULL) {
    CS_Compiler *compiler = cs_get_current_compiler();
    storage = compiler->storage;
  }
}

void delete_storage() {
  if (storage != NULL) {
    MEM_dispose(storage);
  }
}

static Expression *cs_create_expression(ExpressionKind ekind) {
  init_storage();
  Expression *expr =
      (Expression *)MEM_storage_malloc(storage, sizeof(Expression));
  expr->kind = ekind;
  return expr;
}

Expression *cs_create_double_expression(double v) {
  Expression *expr = cs_create_expression(DOUBLE_EXPRESSION);
  expr->u.double_value = v;
  return expr;
}

Expression *cs_create_int_expression(int val) {
  Expression *expression = cs_create_expression(INT_EXPRESSION);
  expression->u.int_value = val;
  return expression;
}

Expression *cs_create_identifier_expression(char *identifier) {
  Expression *expr = cs_create_expression(IDENTIFIER_EXPRESSION);
  expr->u.identifier.name = identifier;
  return expr;
}

Expression *cs_create_inc_dec_expression(Expression *id_expr,
                                         ExpressionKind inc_dec) {
  Expression *expr = cs_create_expression(inc_dec);
  expr->u.inc_dec = id_expr;
  return expr;
}

// args is argument not yet
Expression *cs_create_function_call_expression(Expression *function,
                                               void *args) {
  Expression *expr = cs_create_expression(FUNCTION_CALL_EXPRESSION);
  expr->u.function_call_expression.function = function;
  return expr;
}

Expression *cs_create_minus_expression(Expression *operand) {
  Expression *expr = cs_create_expression(MINUS_EXPRESSION);
  expr->u.minus_expression = operand;
  return expr;
}

Expression *cs_create_logical_not_expression(Expression *operand) {
  Expression *expr = cs_create_expression(LOGICAL_NOT_EXPRESSION);
  expr->u.logical_not_expression = operand;
  return expr;
}

Expression *cs_create_boolean_expression(CS_Boolean boolean_value) {
  Expression *expression = cs_create_expression(BOOLEAN_EXPRESSION);
  expression->u.boolean_value = boolean_value;
  return expression;
}

Expression *cs_create_binaly_expression(ExpressionKind kind, Expression *left,
                                        Expression *right) {
  Expression *expr = cs_create_expression(kind);
  expr->u.binary_expression.left = left;
  expr->u.binary_expression.right = right;
  return expr;
}

Expression *cs_create_assignment_expression(Expression *left,
                                            AssignmentOperator aope,
                                            Expression *operand) {
  Expression *expr = cs_create_expression(ASSIGN_EXPRESSION);
  expr->u.assignment_expression.aope = aope;
  expr->u.assignment_expression.left = left;
  expr->u.assignment_expression.right = operand;
  return expr;
}

char *cs_create_identifier(const char *str) {
  char *new_char;
  new_char = (char *)MEM_storage_malloc(storage, strlen(str) + 1);
  strcpy(new_char, str);
  return new_char;
}

ExpressionList *cs_chain_expression_list(ExpressionList *list,
                                         Expression *expr) {
  ExpressionList *p = list;
  ExpressionList *nlist =
      (ExpressionList *)MEM_storage_malloc(storage, sizeof(ExpressionList));
  nlist->next = NULL;
  nlist->expression = expr;
  if (p != NULL) {
    while (p->next)
      p = p->next;
    p->next = nlist;
    return list;
  }
  return nlist;
}
