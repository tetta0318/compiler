#include "parser.h"
#include "lex.h"

void print_tree(char comment[], int depth){
  for(int i = 0; i < depth; i++) printf("  ");
  printf("%s\n", comment);
  return;
}

void print_tree_value(int value, int depth){
  for(int i = 0; i < depth; i++) printf("  ");
  printf(":%d\n", value);
}

int expr(char *e, int read_pos, int depth){
  Token *t = lex(e, read_pos);

  print_tree("expression", depth);

  int flg = term(e, read_pos, depth + 1);

  t = lex(e, flg);
  //printf("[DEBBUG] %d, %d, %d\n", t->value, t->kind, t->read_pos);

  while(t->kind == PLUS || t->kind == MINUS){
    print_tree("+ | -", depth);
    flg = term(e, flg + 1, depth + 1);
    t = lex(e, flg);
  }

  return flg;
}

int term(char *e, int read_pos, int depth){
  Token *t = lex(e, read_pos);

  print_tree("term", depth);

  int flg = factor(e, read_pos, depth + 1);

  t = lex(e, flg);

  while(t->kind == TIMES || t->kind == MINUS){
    print_tree("* | /", depth);
    flg = term(e, flg + 1, depth + 1);
    t = lex(e, flg);
  }

  return flg;
}

int factor(char *e, int read_pos, int depth){
  int flg;
  Token *t = lex(e, read_pos);

  print_tree("factor", depth);

  if(t->kind == VALUE){
    print_tree_value(t->value, depth);
    return t->read_pos;
  // 左かっこがきたら
  }else if(t->kind == RIGHT){
    print_tree("(", depth);

    //中身がexpressionであることを確かめて
    flg = expr(e, read_pos + 1, depth + 1);

    //右かっこが来ることを確かめる 
    t = lex(e, flg);
    if(t->kind == LEFT){
      print_tree(")", depth);
      flg++;
    }
  }else if(t->kind == END){

  }

  return flg;
}

int main(int argc, char *argv[]){
  Token *token;

  // if(argc == 1 || argc < 2) printf("[ERROR ] invalid argument\n");

  char e[] = "(22+3)*5";

  expr(e, 0, 0);

  return 0;
}
