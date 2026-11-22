#include "MEM.h"
#include <stdio.h>

int main() {
  char *ptr;

  ptr = (char *)MEM_malloc(10);

  for (int i = 0; i < 10; i++) {
    ptr[i] = 0xaa;
  }

  MEM_dump_memory();
  MEM_free(ptr);
  MEM_dump_memory();

  MEM_Storage storage = MEM_open_storage(0);
  ptr = MEM_storage_malloc(storage, 17);
  for (int i = 0; i < 17; i++)
    ptr[i] = 0xee;

  ptr = MEM_storage_malloc(storage, 10);
  for (int i = 0; i < 10; i++)
    ptr[i] = 0xef;

  printf("--------------------------\n");
  MEM_dump_memory();
  MEM_dispose(storage);
  MEM_dump_memory();

  return 0;
}
