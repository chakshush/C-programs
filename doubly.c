#include<stdio.h>
struct node{
  int data;
  struct node *prev;
  struct node *next;
};
struct node *head=NULL;
void insertbeg(struct node **hr, int data) {
    struct node *new =(struct node*)malloc(sizeof(struct node));
    new->data=data;
    new->next=(*hr);
    new->prev=NULL;
    if((*hr)!=NULL) (*hr)->prev=new;
    (*hr)=new;
}
void insertloc(struct node **hr, int count,int data){
    if(*hr==NULL) return;
    struct node* new=(struct node*)malloc(sizeof(struct node));
    struct node* pre=*hr;
    while(count>1){
      pre=pre->next;
      if(pre==NULL) return;
      count--;
    }
    new->data=data;
    new->next=pre->next;
    pre->next=new;
    new->prev=pre;
    if(new->next!=NULL) new->next->prev=new;
}
void insertend(struct node** hr, int data){
    struct node* node=(struct node*)malloc(sizeof(struct node));
    struct node* last=*hr;
    node->data=data;
    node->next=NULL;
    if(*hr == NULL){
        node->prev = NULL;
        *hr = node;
        return;
    }
    while(last->next!=NULL) last = last->next;
    last->next=node;
    node->prev=last;
    return;
}
void deleteNode(struct node** hr, int count){
    if(*hr==NULL) return;
    struct node* del=*hr;
    while(count>1){
      del=del->next;
      if(del==NULL) return;
      count--;
    }
    if (del->next != NULL) del->next->prev = del->prev;
    if (del->prev != NULL) del->prev->next = del->next;
    free(del);
    return;
}
void traverse(){
    struct node* last=head;
    while(last!=NULL){
        printf(" %d ",last->data);
        last=last->next;
    }
    printf(" \n");
}
int main(){
  int m,l;
  printf(" 1.insert at beginning \n 2.insert after location \n 3.insert at end \n 4. delete after location \n");
  loop:
  scanf("%d",&m);
  switch(m){
    case 1:
      printf("data: ");
      scanf("%d",&m);
      insertbeg(&head,m);
      traverse();
      break;
    case 2:
      printf("location: ");
      scanf("%d",&l);
      printf("data: ");
      scanf("%d",&m);
      insertloc(&head,l,m);
      traverse();
      break;
    case 3:
      printf("data: ");
      scanf("%d",&m);
      insertend(&head,m);
      traverse();
      break;
    case 4:
      printf("location: ");
      scanf("%d",&m);
      deleteNode(&head,m);
      traverse();
      break;
    default:
      return 0;
      break;
  }
  goto loop;
}
