extern int stack[100];
extern int counter;

void push(int value){
  counter++;
  stack[counter] = value;
  return;
}