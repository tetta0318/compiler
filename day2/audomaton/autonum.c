#include <stdio.h>
#include <stdlib.h>

#define STR_LEN 100

typedef enum{
  s0,
  s1,
  s2,
  s3
} State;

int automaton(char s[]){
  State state = s0;
  int counter = 0;
  int accept_counter = 0; 

  while(1){

    char t = s[counter];
    
    switch(state){
    case s0:
      if(t == '0'){
        state = s2;
      }else if('1' <= t && t <= '9'){
        state = s1;
      }else{
        printf("[ERROR ] invalid input: %c\n", t);
        return -1;
      } 

      break;

    case s1:
      if('0' <= t && t <= '9'){
        state = s1;
        counter++;
        accept_counter++;
      }else if(t == ' ' || t == '\n'){
        state = s3;
      }else{
        printf("[ERROR ] invalid input: %c\n", t);
        return -1;
      }

      break;

    case s2:
      state = s3;
      counter++;
      accept_counter++;
      
      break;


    case s3:{
      if (t != ' ' || t != '\n'){
        printf("[ERROR ] invalid input: %c\n", t);
      }
      char tmp[accept_counter + 1];
      for(int i = 0; i < accept_counter; i++){
        tmp[i] = s[counter - accept_counter + i];
      }
      tmp[accept_counter] = '\0';
      printf("accept val = %d\n", atoi(tmp));
      accept_counter = 0;

      if(t == ' '){
        state = s0;
        counter++;
      }else if(t == '\n'){
        return 0;
      }
      break;
    }
    }
    // printf("[DEBUG ] char: %c, state: %d, counter: %d\n", s[counter], state, counter);
  }
  return 0;
}

int main(){
  char s[STR_LEN];

  printf("INPUT: ");
  fgets(s, STR_LEN, stdin);

  if(automaton(s) != 0){
    printf("faild\n");
  }

  return 0;
}