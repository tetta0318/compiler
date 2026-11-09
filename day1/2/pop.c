extern int stack[100];
extern int counter;

int pop(){
  int i = stack[counter];
  counter--;
  return i; 
}