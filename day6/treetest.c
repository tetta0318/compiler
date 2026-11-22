#include "MEM.h"
#include "visitor.h"
#include <stdio.h>

int main(void) {
  Expression *expr = cs_create_int_expression(10);
  printf("treetest\n");

  Visitor *visitor = create_treeview_visitor(); //  Visitorを作成
  traverse_expr(expr, visitor);                 //  探索の実行

  delete_visitor(visitor); // メモリの開放
  delete_storage();
  MEM_dump_memory();

  return 0;
}
