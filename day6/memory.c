#include "MEM.h"
#include <stdio.h>
#include <stdlib.h>

static MEM_module *head = NULL;

void *MEM_malloc(size_t size) {
  MEM_module *module;

  module = (MEM_module *)malloc(sizeof(MEM_module));
  if (!module) {
    printf("malloc failure in memory.c:12\n");
    return NULL;
  }

  module->ptr = (void *)malloc(size);
  if (!module->ptr) {
    printf("malloc failure\n");
    return NULL;
  }
  module->buf_size = size;
  module->next = head;
  head = module;

  return module->ptr;
}

void *MEM_realloc(void *ptr, size_t size) {
  MEM_module *entry;
  size_t alloc_size;
  entry = find_module(ptr);

  alloc_size = size + entry->buf_size;

  if (!realloc(ptr, alloc_size)) {
    printf("realloc failure in memory.c:36\n");
    return NULL;
  }

  return ptr;
}

void MEM_free(void *ptr) {
  MEM_module *entry = head;
  MEM_module *prev = NULL;

  for (; entry; entry = entry->next) {
    if (entry->ptr == ptr)
      break;
    prev = entry;
  }

  if (!entry)
    return;

  if (prev == NULL)
    head = entry->next;
  else
    prev->next = entry->next;

  free(entry->ptr);
  free(entry);
}

void MEM_dump_memory() {
  MEM_module *entry = head;

  if (!entry) {
    printf("no allocated memory\n");
    return;
  }

  while (entry) {
    unsigned char *buf = entry->ptr;

    printf("-------------------------\n");
    printf("size %zu, head:%p\n", entry->buf_size, entry->ptr);
    printf("-------------------------\n");
    for (int i = 0; i < entry->buf_size; i++) {
      printf("%02x ", (unsigned int)buf[i]);
      if ((i + 1) % 16 == 0)
        printf("\n");
    }

    printf("\n");
    entry = entry->next;
  }

  return;
}

MEM_module *find_module(void *ptr) {
  MEM_module *entry;

  for (entry = head; entry; entry = entry->next) {
    if (entry->ptr == ptr)
      return entry;
  }

  printf("module not found\n");
  return NULL;
}
