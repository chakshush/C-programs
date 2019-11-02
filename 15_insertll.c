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
        printf("\nEnter the element to insert in the list: ");
        temp=(struct node*)malloc(sizeof(struct node*));
        scanf("%d", &temp->data);
        printf("\nWhere would you like to insert the element:\n1. Beginning\n2. Ending\n3. At a specified node\nYour choice: ");
        scanf("%d", &ch);
        if(ch==1)
        {
                temp->next=start;
                start=temp;
                printf("\nThe node has been added at the start! ");
                displl(start);
        }
        else if(ch==2)
        {
                last->next=temp;
                last=temp;
                displl(start);
        }
        else if(ch==3)
        {
                printf("\nEnter the index of the position where the node is to be inserted: ");
                scanf("%d", &ind);
                struct node*temp1=(struct node*)malloc(sizeof(struct node*));
                temp1=start;
                for(i=1; i<ind-1; i++)
                {
                        temp1=temp1->next;
                }
                temp->next=temp1->next;
                temp1->next=temp;
                displl(start);
        }

        return 0;

}
