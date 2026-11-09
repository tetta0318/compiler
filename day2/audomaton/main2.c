#include <stdio.h>
#include "id2.h"
#include <string.h>

  extern struct OPE *in_word_set(char*, unsigned int);

int main(int argc, char* argv[]){
  struct OPE *p;
  if(argc == 1){
    return 1;
  }

  p = in_word_set(argv[1], strlen(argv[1]));

  if(p == NULL){
    printf("no match!\n");
  }else{
    printf("match!\n");
    printf("name  = %s\n", p->name);
    printf("type  = %d\n", p->type);
    printf("state = %d\n", p->state);
  }

  return 0;
}