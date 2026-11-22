#include <stdio.h>
#include <stdlib.h>

#include "MEM.h"

struct MEM_page_tag {
  void *ptr;
  size_t used_size;
  MEM_page next;
};

struct MEM_Storage_tag {
  MEM_page head;
  size_t page_size;
};

MEM_Storage MEM_open_storage(int page_size) {
  MEM_Storage storage;

  storage = (MEM_Storage)MEM_malloc(sizeof(struct MEM_Storage_tag));
  if (!storage) {
    printf("MEM_malloc failed in storage.c:%d\n", __LINE__);
  }

  storage->head = NULL;
  storage->page_size = page_size;
  if (page_size == 0) {
    storage->page_size = DEFAULT_PAGE_SIZE;
  }

  return storage;
}

void *MEM_storage_malloc(MEM_Storage storage, size_t size) {
  MEM_page page = storage->head;

  if (page == NULL) {
    page = MEM_page_init(storage->page_size);
    if (!page) {
      printf("MEM_page_init failure in storage.c:%d\n", __LINE__);
      return NULL;
    }
    page->used_size = size;
    storage->head = page;
    return page->ptr;
  }

  while (page->next)
    page = page->next;

  size_t alignment = _Alignof(max_align_t);
  size_t padding = (alignment - page->used_size % alignment) % alignment;

  if (page->used_size + size + padding > storage->page_size) {
    MEM_page next_page = MEM_page_init(storage->page_size);
    if (!next_page) {
      printf("MEM_page_init failure in storage.c:%d\n", __LINE__);
      return NULL;
    }
    next_page->used_size = size;
    page->next = next_page;
    return next_page->ptr;
  }

  void *ptr = (char *)page->ptr + page->used_size + padding;
  page->used_size += size + padding;
  return ptr;
}

void MEM_dispose(MEM_Storage storage) {
  MEM_page_dispose(storage->head);
  MEM_free(storage);
}

MEM_page MEM_page_init(size_t page_size) {
  MEM_page page;
  page = MEM_malloc(sizeof(struct MEM_page_tag));
  if (!page) {
    printf("malloc failure in storage.c:%d\n", __LINE__);
    return NULL;
  }
  page->ptr = MEM_malloc(page_size);
  if (!page->ptr) {
    printf("malloc failure in storage.c:%d\n", __LINE__);
    free(page);
    return NULL;
  }
  page->next = NULL;
  page->used_size = 0;

  return page;
}

void MEM_page_dispose(MEM_page page) {
  if (!page) {
    return;
  }

  MEM_page_dispose(page->next);

  MEM_free(page->ptr);
  MEM_free(page);
}
