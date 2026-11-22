#ifndef VISITOR_H_
#define VISITOR_H_

#include "csua.h"

typedef struct Visitor_tag Visitor;

typedef void (*visit_expr)(Expression *expr);

struct Visitor_tag {
  visit_expr *enter_expr_list;
  visit_expr *leave_expr_list;
};

Visitor *create_treeview_visitor();
void delete_visitor(Visitor *visitor);

void traverse_expr(Expression *expr, Visitor *visitor);
static void traverse_expr_children(Expression *expr, Visitor *visitor);

#endif
