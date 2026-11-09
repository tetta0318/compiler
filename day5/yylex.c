#include "yylex.h"

FILE *yyin = NULL;
char yytext[1026];
YYSTYPE yylval;

size_t n_chars;
static char *ch_buf_p = NULL;

BUFFER_STATE *create_buffer(FILE *file){
  BUFFER_STATE *b;
  b = (BUFFER_STATE *) malloc(sizeof(BUFFER_STATE));

  if(!b){
    printf("[ERROR ] malloc failure in yylex.c:13\n");
    return NULL; 
  }

  b->input_file = file;
  b->ch_buf[0] = EOF;
  b->has_next = 0;
  return b;
}

void get_next_buffer(){
  int i;
  int c = '*';
  char buf[BUF_SIZE + 2];

  for(i = 0; i < BUF_SIZE; i++){
    c = fgetc(yyin);
    buf[i] = (char)c;
    if(c == EOF){
      break;
    }
  }
  // EOFがあるかbufsizeを超えたらEOFを書き込むようにする
  // 構造体に書き込むと時間がかかるからmemcpyとbufを用いて書く

  if(i == 1024){
    buf[i] = EOF;
    buffer_state->has_next = 1;
  }

  memcpy(buffer_state->ch_buf, buf, sizeof(buf));
  ch_buf_p = buffer_state->ch_buf;
  return;
}

int yylex(){
  int kind;
  char *cp, *bp;
  char buf[32];
  STATE state = START;

  if(buffer_state == NULL){
    buffer_state = create_buffer(yyin);
    if(!buffer_state){
      printf("faild create_buffer() in yylex.c:36\n");
      return 0;
    }
    get_next_buffer();
  }

  cp = ch_buf_p;
  bp = cp;

  while(1){

    switch(state){
      case START:
      if('1' <= *bp && *bp <= '9') state = VALUE;
      else if('a' <= *bp && *bp <= 'z') state = CHAR;
      else if(*bp == '0') state = ZERO;
      else if(*bp == '+') {state = PLUS; bp++;}
      else if(*bp == '-') {state = MINUS; bp++;}
      else if(*bp == '*') {state = TIMES; bp++;}
      else if(*bp == '/') {state = DIVISION; bp++;}
      else if(*bp == '%') {state = MODULO; bp++;}
      else if(*bp == '&') {state = AMPERSAND; bp++;}
      else if(*bp == '|') {state = PIPE; bp++;}
      else if(*bp == '=') {state = EQUAL; bp++;}
      else if(*bp == '!') {state = EXCLAMATION; bp++;}
      else if(*bp == '>') {state = GREATER; bp++;}
      else if(*bp == '<') {state = LESS; bp++;}
      else if(strchr(";(){}", *bp) != NULL) state = SYMBOL;
      else if(*bp == EOF) state = END_OF_FILE;
      else state = DEFAULT;
      break;

      case VALUE:
      if('0' <= *bp && *bp <= '9'){
        bp++;
      }else{
        kind = INT_LITERAL;
        memcpy(buf, cp, (size_t)(bp - cp + 1));
        yylval.iv = atoi(buf);
        state = END;
      }
      break;

    
      case CHAR:{
      if(('a' <= *bp && *bp <= 'z') || ('A' <= *bp && *bp <= 'Z') || ('0' <= *bp && *bp <= '9') || *bp == '_'){
        bp++;
      }else{
        size_t len = (size_t)(bp - cp);
        memcpy(yytext, cp, len);
        yytext[len] = '\0';
        struct RESERVED_WORD *p = in_word_set(yytext, len);
        if(p){
          kind = p->token_type;
        }else{
          kind = IDENTIFIER;
          yylval.name = yytext;
        }
        state = END;
      }
      break;
      }

      case PLUS:
      if(*bp == '=') {kind = ADD_ASSIGN; bp++;}
      else kind = ADD;
      state = END;
      break;

      case MINUS:
      if(*bp == '=') {kind = SUB_ASSIGN; bp++;}
      else kind = SUB;
      state = END;
      break;

      case TIMES:
      if(*bp == '=') {kind = MUL_ASSIGN; bp++;}
      else kind = MUL;
      state = END;
      break;

      case DIVISION:
      if(*bp == '=') {kind = DIV_ASSIGN; bp++;}
      else kind = DIV;
      state = END;
      break;

      case MODULO:
      state = END;
      break;

      case AMPERSAND:
      if(*bp == '&') {kind = AND; bp++;}
      else kind = BIT_AND;
      state = END;
      break;

      case PIPE:
      if(*bp == '|') {kind = OR; bp++;}
      else kind = BIT_OR;
      state = END;
      break;

      case EQUAL:
      if(*bp == '=') {kind = EQ; bp++;}
      else kind = ASSIGN;
      state = END;
      break;

      case EXCLAMATION:
      if(*bp == '=') {kind = NE; bp++;}
      else kind = NOT;
      state = END;
      break;

      case GREATER:
      if(*bp == '=') {kind = GE; bp++;}
      else kind = GT;
      state = END;
      break;

      case LESS:
      if(*bp == '=') {kind = LE; bp++;}
      else kind = LT;
      state = END;
      break;

      case OPERATER:
      bp++;
      break;


      case SYMBOL:
      if(*bp == ';') kind = SEMICOLON;
      else if(*bp == ' ') kind = SPACE;
      else if(*bp == '\n') kind = CR;
      else if(*bp == '(') kind = LPAREN;
      else if(*bp == ')') kind = RPAREN;
      else if(*bp == '{') kind = LBRACE;
      else if(*bp == '}') kind = RBRACE;
      bp++;
      state = END;
      break;


      case END_OF_FILE:
      if(buffer_state->has_next){
        get_next_buffer();
      }else{
        kind = EOF;
        state = END;
      }
      break;

      case END:
      ch_buf_p = bp;
      return kind;

      case DEFAULT:
      bp++;
      kind = CR;
      state = END;
      break;
      

      default:
      break;
    }
    //printf("%d, %c\n", state, *bp);
  }

  return 0;
}