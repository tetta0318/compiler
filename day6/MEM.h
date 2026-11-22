#ifndef _MEM_H_
#define _MEM_H_

#include <stddef.h>

#define DEFAULT_PAGE_SIZE 1024

typedef struct MEM_module {
  void *ptr;
  size_t buf_size;
  struct MEM_module *next;
} MEM_module;

typedef struct MEM_page_tag *MEM_page;
typedef struct MEM_Storage_tag *MEM_Storage;

void *MEM_malloc(size_t size);
void *MEM_realloc(void *ptr, size_t size);
void MEM_free(void *ptr);
void MEM_dump_memory();

MEM_Storage MEM_open_storage(int page_size);
void *MEM_storage_malloc(MEM_Storage storage, size_t size);
void MEM_dispose(MEM_Storage storage);

MEM_module *find_module(void *ptr);
MEM_page MEM_page_init(size_t page_size);
void MEM_page_dispose(MEM_page page);

#endif
