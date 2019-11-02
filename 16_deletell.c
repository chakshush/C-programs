#include <stdio.h>
#include<stdlib.h>
struct node
{
        int data;
        struct node *next;
};
void displl(struct node *start)
{
        struct node*temp=start;
        printf("\nThe linked list now is: ");
        while(temp!=NULL)
        {
                printf("%d ", temp->data);
                temp=temp->next;
        }
}
int main()
{
        int n, i, ch, ind;
        struct node *temp=NULL, *start=NULL, *last=NULL;
        printf("\nEnter the number of nodes in the linked list: ");
        scanf("%d", &n);
        printf("\nEnter the datas of the nodes: ");
        for(i=0; i<n; i++)
        {
                temp=(struct node*)malloc(sizeof(struct node*));
                scanf("%d", &temp->data);
                temp->next=NULL;
                if(start==NULL)
                {
                        start=temp;
                        last=temp;
                }
                else
                {
                        last->next=temp;
                        last=temp;
                }
        }
        printf("\nWhich node would you like to delete in the list:\n1. First node\n2. Last node\n3. A specified node\nYour choice: ");
        scanf("%d", &ch);
        if(ch==1)
        {
                temp=start;
                start=start->next;
                free(temp);
                printf("\nThe first node has been deleted! ");
                displl(start);
        }
        else if(ch==2)
        {
                while(temp->next!=NULL)
                        temp=temp->next;
                last=temp;
                temp=temp->next;
                free(temp);
                printf("\nLast node has been deleted!" );
                displl(start);
        }
        else if(ch==3)
        {
                printf("\nEnter the index of the node to be deleted: ");
                scanf("%d", &ind);
                struct node*temp1=(struct node*)malloc(sizeof(struct node*));
                temp1=start;
                for(i=1; i<ind-1; i++)
                {
                        temp1=temp1->next;
                }
                temp=temp1->next;
                temp1->next=temp->next;
                free(temp);
                displl(start);
        }

        return 0;

}
