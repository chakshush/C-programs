#include<stdio.h>
struct tree{
  int data;
  struct tree* left;
  struct tree* right;
};
struct tree* create(int data){
  struct tree* temp=(struct tree*)malloc(sizeof(struct tree));
  temp->data=data;
  temp->left=NULL;
  temp->right=NULL;
  return (temp);
}
void postorder(struct tree* temp){
  if(temp==NULL) return;
  postorder(temp->left);
  postorder(temp->right);
  printf("%d ",temp->data);
}
void inorder(struct tree* temp){
  if(temp==NULL) return;
  inorder(temp->left);
  printf("%d ",temp->data);
  inorder(temp->right);
}
void preorder(struct tree* temp){
  if(temp==NULL) return;
  printf("%d ",temp->data);
  preorder(temp->left);
  preorder(temp->right);
}
int main(){
  struct tree* root=create(5);
  root->left=create(4);
  root->right=create(3);
  root->left->right=create(2);
  root->right->left=create(1);
  root->right->right=create(0);
  printf("Inorder traversal \n");inorder(root);
  printf("\nPreorder traversal \n");preorder(root);
  printf("\nPostorder traversal \n");postorder(root);
  return 0;
}
