#include <stdio.h>
#include <stdlib.h>
struct tree
{
        int data;
        struct tree *left;
        struct tree *right;
} *root=NULL, *temp=NULL, *mroot=NULL, *proot=NULL;
void inserttree(struct tree *proot, struct tree *root, int val)
{

        if(root==NULL)
        {
                temp=(struct tree*) malloc(sizeof(struct tree));
                temp->data=val;
                temp->left=NULL;
                temp->right=NULL;
                root=temp;
                if(proot==NULL)
                        mroot=temp;
                if(proot!=NULL)
                {
                        if(val>proot->data)
                                proot->right=root;
                        else
                                proot->left=root;
                }
                printf("\nElement added!" );
        }
        else
        {
                if(val>root->data)
                        inserttree(root, root->right, val);
                else
                        inserttree(root, root->left, val);
        }
}
struct tree *largestnode(struct tree *root)
{
        if(root->right==NULL)
                return root;
        else
                largestnode(root->right);
}
void deletetree(struct tree *root, int val)
{
        if(root==NULL)
                printf("\nValue not found. ");
        else if(root->data>val)
                deletetree(root->left, val);
        else if(root->data<val)
                deletetree(root->right, val);
        else if(root->data==val)
        {
                if(root->left==NULL && root->right==NULL)
                {
                        free(root);
                        root=NULL;
                        printf("\nElement deleted!" );
                }
                else if(root->left==NULL)
                {
                        temp=root->right;
                        root->data=temp->data;
                        free(temp);
                        temp=NULL;
                        printf("\nElement deleted!" );
                }
                else if(root->right==NULL)
                {
                        temp=root->left;
                        root->data=temp->data;
                        free(temp);
                        temp=NULL;
                        printf("\nElement deleted!" );
                }
                else if(root->right!=NULL && root->left!=NULL)
                {
                        struct tree *temp;
                        temp=largestnode(root->left);
                        root->data=temp->data;
                        printf("\nElement deleted!" );
                        deletetree(root->left, temp->data);
                }
        }
}
void inord(struct tree *root)
{
        if(root!=NULL)
        {
                inord(root->left);
                printf("%d ", root->data);
                inord(root->right);
        }

}
int main()
{
        int ch=0; int val;
        while(ch!=4){
        printf("\nWhat operation would you like to do? \n1 Insert into the tree\n2. Delete an element in the tree\n3. Traverse through the tree\n4. Exit\nYour choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
                case 1: printf("\nEnter the data to be inserted: ");
                        scanf("%d", &val);
                        inserttree(proot, mroot, val);
                        break;
                case 2: printf("\nEnter the data to be deleted: ");
                        scanf("%d", &val);
                        deletetree(mroot, val);
                        break;
                case 3: inord(mroot);
                        break;
        }
}
        return 0;

}
