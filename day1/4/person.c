#include <stdio.h>
#include <stdlib.h>

#define NAME_LEN 30

typedef struct person {
  int id;
  char name[NAME_LEN];
  int age;
  struct person *next;
} PERSON;

void showList(PERSON *person){
  PERSON *entry;
  for(entry = person; entry; entry = entry->next){
    printf("ID : %d\n", entry->id);
    printf("Name : %s\n", entry->name);
    printf("Age : %d\n", entry->age);
  }
}

int main(){
  int i;
  PERSON *head = NULL;
  PERSON *tail = NULL;

  while(1){
    PERSON *tmp = (PERSON *)malloc(sizeof(PERSON));
    printf("ID : ");
    scanf("%d", &i);
    if(i == -1) break;
    tmp->id = i;
    printf("Name : ");
    scanf("%s", tmp->name);
    printf("Age : ");
    scanf("%d", &tmp->age);
    
    if(head == NULL){
      head = tmp;
      tail = tmp;
    }else{
      tail->next = tmp;
      tail = tmp;
    }
  }

  showList(head);
}