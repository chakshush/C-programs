#include<stdio.h>
#define max 10
int rear=-1,front=-1,queue[max];
void insert(int);
void traverse();
void delete();
int main(){
  int s;
  command:
  printf("\n Select operation \n (1)Insert (2)Delete (3)Display:- ");
  scanf("%d",&s);
  switch(s){
    case 1:
      printf("Input value? :- ");
      scanf("%d",&s);
      insert(s);
      goto command;
    case 2:
      delete();
      goto command;
    case 3:
      traverse();
      goto command;
    default:
      printf("Invalid input \n");
      goto command;
  }
}
void insert(int a){
  if(rear==max-1){
    printf("overflow \n");
    return;
  }
  if(front==-1&&rear==-1) {
    front=0;
    rear=0;
  }
  else rear++;
  queue[rear]=a;
}
void traverse(){
  if (front==-1||front>rear) printf("NULL \n");
  else for(int i=front;i<=rear;i++) printf("%d \n",queue[i]);
}
void delete(){
  if(front==-1||front>rear){
    printf("Underflow \n");
    return;
  }
  else printf("removed value was %d \n",queue[front++]);
}
