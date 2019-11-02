#include<stdio.h>
#include<stdlib.h>
struct node{
  int num;
  struct node *p;
};
typedef struct node ll;
int m=0,i,n;
void create(ll **hr,int d){
  ll *new=(ll*) malloc(sizeof(ll));
  new->num=d;
  new->p=(*hr);
  (*hr)=new;
}
void print(ll *node){
  printf(" \n");
  while(node!=NULL){
     printf("%d \n",node->num);
     node=node->p;
  }
  printf(" \n");
}
void deletebeg(ll **hr){
   if(*hr==NULL){
      printf("List is Empty! \n");
      return;
   }
   ll *temp=*hr;
   *hr=temp->p;
   free(temp);
   n--;
}
void deletepos(ll **hr,int pos){
   if(*hr==NULL){
      printf("List is Empty! \n");
      return;
   }
   ll *temp=*hr;
   for(int i=0;temp!=NULL && i<pos-1;i++) temp=temp->p;
   if(temp==NULL||temp->p==NULL) return;
   ll *p=temp->p->p;
   free(temp->p);
   temp->p=p;
   n--;
}
void deleteend(ll **hr){
   if(*hr==NULL){
      printf("List is Empty! \n");
      return;
   }
   ll *temp=*hr;
   for(int i=0;temp!=NULL&&i<n-2;i++) temp=temp->p;
   if(temp==NULL||temp->p==NULL) return;
   ll *p=temp->p->p;
   free(temp->p);
   temp->p=p;
   n--;
}
int main(){
  ll *head;
  head=NULL;
  printf("Create a linked list \n Enter no. of elements: ");
  scanf("%d",&n);
  for(i=0;i<n;i++){
    printf("enter data \n");
    scanf("%d",&m);
    create(&head,m);
  }
  print(head);
  printf("Select operation \n 1.deletion at beginning \n 2.deletion at a location \n 3.deletion at the end \n 4.exit program \n");
  loop:
  printf("Select operation: \n");
  scanf("%d",&m);
  switch(m){
    case 1:
      deletebeg(&head);
      break;
    case 2:
      printf("Enter position: ");
      scanf("%d",&m);
      deletepos(&head,m);
      break;
    case 3:
      deleteend(&head);
      break;
    case 4:
      return 0;
  }
  print(head);
  goto loop;
}
