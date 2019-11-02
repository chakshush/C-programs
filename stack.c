#include<stdio.h>
#define max 100
int stack[max],top=-1;
void push(int val){
  if(top==max-1) printf("Overflow \n");
  else{
    top++;
    stack[top]=val;
  }
}
void pop(){
  if(top==-1) printf("Underflow \n");
  else top--;
}
void traverse(){
  int i=0;
  printf("\n");
  if (top==-1) printf("NULL \n");
  else{
    for(i=top;i>=0;i--) printf("%d \n",stack[i]);
  }
  printf("\n");
}
void main(){
  int a,b;
  command:
  printf("\n Select operation \n (1)Push (2)Pop :- ");
  scanf("%d",&a);
  switch(a){
    case 1:
     printf("Input value to push to the tos :- ");
     scanf("%d",&b);
     push(b);
     traverse();
     goto command;
    case 2:
      pop();
      traverse();
      goto command;
    default:
      printf("Invalid input \n");
      goto command;
  }
}
