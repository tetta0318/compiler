#include "csua.h"
#include <stdio.h>
#include <stdlib.h>

#include "MEM.h"

int main() {
  FILE *fin = fopen("tests/prog1.cs", "r");
  CS_Compiler *compiler = CS_create_compiler();
  CS_compile(compiler, fin);

  printf("-------------------\n");
  ExpressionList *expr_list = compiler->expr_list;
  while (expr_list) {
    printf("kind = %d\n", expr_list->expression->kind);
    expr_list = expr_list->next;
  }

  fclose(fin);
  CS_delete_compiler(compiler);
  MEM_dump_memory();
  return 0;
}
