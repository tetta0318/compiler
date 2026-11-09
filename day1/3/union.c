#include <stdio.h>

union union_int{
  int i;
  long l;
  short s[2];
  char c[4];
}u;

int main(){
  printf("Val : ");
  scanf("%d", &u.i);

  printf("int    : 0x%08x\n", u.i);
  printf("long   : 0x%08lx\n", u.l);
  printf("short  : 0x%04x, 0x%04x\n", u.s[0], u.s[1]);
  printf("char   : 0x%02x, 0x%02x, 0x%02x, 0x%02x\n", u.c[0], u.c[1], u.c[2], u.c[3]);
}