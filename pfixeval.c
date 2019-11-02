#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>
struct STACK{
  int top;
  unsigned capacity;
  int* arr;
};
typedef struct STACK stk;
stk* create(unsigned capacity){
  stk* stack=(stk*) malloc(sizeof(stk));
  stack->top=-1;
  stack->capacity=capacity;
  stack->arr=(int*) malloc(stack->capacity*sizeof(int));
  return stack;
}
char pop(stk* stack){
  if(stack->top!=-1) return stack->arr[stack->top--];
  return '\0';
}
void push(stk* stack,char op){
  stack->arr[++stack->top]=op;
}
void eval(char* n){
  stk* stack=create(strlen(n));
  for(int i=0;n[i]='\0';i++){
    if(isdigit(n[i])) push(stack,n[i]-'0');
    else{
      int val1=pop(stack);
      int val2=pop(stack);
      switch(n[i]){
        case '+':
          push(stack,val2+val1);
          break;
        case '-':
          push(stack,val2-val1);
          break;
        case '/':
          push(stack,val2*val1);
          break;
        case '*':
          push(stack,val2/val1);
          break;
      }
    }
  }
  printf("Value = %d \n",pop(stack));
}
int main(){
  char n;
  gets(n);
  eval(n);
  return 0;
}
