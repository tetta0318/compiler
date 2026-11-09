#include <stdio.h>
#include <string.h>

int stack[100];
int counter = 0;

void push(int value);
int pop(void);

void show(){
  for(int i = counter; i > 0; i--){
    printf("%d\n", stack[i]);
  }
  return;
}

int main(void){
  char str[30];
  char s1[10];
  int value;

  while(1){
    printf(">");
    fgets(str, sizeof(str), stdin);
    sscanf(str, "%s %d", s1, &value);

    if(strcmp(s1, "push") == 0){
      push(value);
    } else if(strcmp(s1, "pop") == 0){
      printf("%d\n", pop());
    } else if(strcmp(s1, "show") == 0){
      show();
    }
  }

  return 0;
}