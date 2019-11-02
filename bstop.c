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
void inorder(struct tree* tree){
    if(tree==NULL) return;
    inorder(tree->left);
    printf("%d ",tree->data);
    inorder(tree->right);
}
struct tree* min(struct tree* node){
    struct tree* current=node;
    while (current->left!=NULL)current=current->left;
    return current;
}
struct tree* del(struct tree* root, int key){
    if(root==NULL) return root;
    if(key<root->data) root->left=del(root->left,key);
    else if(key>root->data) root->right=del(root->right,key);
    else{
        if(root->left==NULL){
            struct tree *temp=root->right;
            free(root);
            return temp;
        }
        else if(root->right==NULL){
            struct tree *temp=root->left;
            free(root);
            return temp;
        }
        struct tree* temp=min(root->right);
        root->data=temp->data;
        root->right=del(root->right, temp->data);
    }
    return root;
}
int main (){
    static i,n;
    struct tree* root=create(5);
    root->left=create(4);
    root->right=create(3);
    root->left->right=create(2);
    root->right->left=create(1);
    root->right->right=create(0);
    printf("Inorder traversal of the given tree: \n");
    inorder(root);
    printf("\ninput value to delete ");
    scanf("%d",&i);
    del(root,i);
    inorder(root);
    return 0;
}
