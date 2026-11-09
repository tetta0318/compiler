#include "lex.h"
#include "parser.h"

Token *lex(char s[], int counter){
  State state = s0;
  int accept_counter = 0;

  Token *token;
  token = malloc(sizeof(Token));

  while(1){
    char t = s[counter];

    switch(state){
      case s0:
      if(t == '0'){
        state = s2;
      }else if('1' <= t && t <= '9'){
        state = s1;
      }else if(t == '+' || t == '-' || t == '*' || t == '/' || t == '(' || t == ')' || t == '\0'){
        state = s3;
      }else{
        printf("[ERROR ] invalid input: %c\n", t);
        return NULL;
      }
      break;


      case s1: {
      if('0' <= t && t <= '9'){
        counter++;
        accept_counter++;
      }else{
        char buf[accept_counter];
        for(int i = 0; i < accept_counter + 1; i++){
          buf[i] = s[counter - accept_counter + i];
        }
        token->value = atoi(buf);
        token->kind = VALUE;
        state = s4;
      }
      break;
      }

      case s2:
      counter++;
      token->value = 0;
      state = s4;
      
      break;


      case s3:
      counter++;
      if(t == '+') token->kind = PLUS;
      else if(t == '-') token->kind = MINUS;
      else if(t == '*') token->kind = TIMES;
      else if(t == '/') token->kind = DIVIDE;
      else if(t == '(') token->kind = RIGHT;
      else if(t == ')') token->kind = LEFT;
      else if(t == '\0') token->kind = END;
      state = s4;

      break;

      case s4:
      token->read_pos = counter;
      accept_counter = 0;
      return token;
      break;

    }
  }

  return NULL;

}

