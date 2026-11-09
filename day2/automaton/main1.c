#include <stdio.h>
#include <string.h>

extern const char* in_word_set(char*, unsigned int);

int main(int argc, char *argv[]){
  const char *p = NULL;
  if(argc == 1){
    return 0;
  }

  p = in_word_set(argv[1], strlen(argv[1]));
  if(p == NULL){
    printf("no match\n");
  } else{
    printf("hit [%s]\n", p);
  }
  return 0;
}