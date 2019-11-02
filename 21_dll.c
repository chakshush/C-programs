#include <stdio.h>
#include <stdlib.h>
struct node
{
        int data;
        struct node *next;
        struct node *prev;
};
int main()
{
        int ch, ch1, ch2, ind, i;
        struct node *temp=NULL, *start=NULL, *last=NULL;
        while(ch!=4)
        {
                printf("\nWhat would you like to do?\n1. Add a node. \n2. Delete a node.\n3. Traverse through the list.\n4. Exit.\nYour choice: ");
                scanf("%d", &ch);
                if(ch==1)
                {
                        temp=(struct node*)malloc(sizeof(struct node*));
                        printf("\nEnter the node data: ");
                        scanf("%d", &temp->data);
                        temp->next=NULL;
                        temp->prev=NULL;
                        if(start==NULL)
                        {
                                start=last=temp;
                        }
                        else
                        {
                                printf("\nWhere would you like to add?\n1. Beginning\n2. Ending\n3. At a specified index\nYour choice: ");
                                scanf("%d", &ch1);
                                if(ch1==1)
                                {
                                        temp->next=start;
                                        start->prev=temp;
                                        start=temp;
                                }
                                else if(ch1==2)
                                {
                                        last->next=temp;
                                        temp->prev=last;
                                        last=temp;

                                }
                                else if(ch1==3)
                                {
                                        struct node*temp1;
                                        printf("\nEnter the index where the node is to be added: ");
                                        scanf("%d", &ind);
                                        temp1=start;
                                        for(i=1; i<ind; i++)
                                        {
                                                temp1=temp1->next;
                                        }
                                        temp->prev=temp1->prev;
                                        temp->next=temp1;
                                        temp1->prev=temp;
                                        temp1=temp->prev;
                                        temp1->next=temp;
                                }
                        }
                        printf("\nNode added! ");

                }
                else if(ch==2)
                {
                        if(start==NULL)
                        {
                                printf("\nUnderflow! ");
                        }
                        else if(start->next==NULL && start->prev==NULL)
                        {
                                temp=start;
                                free(temp);
                                start=NULL;
                                last=NULL;
                                printf("\nNode deleted! List is now empty. ");
                        }
                        else
                        {
                                printf("\nWhich node do you want to delete?\n1. First node\n2. Last node\n3. Node at a specified index\nYour choice: ");
                                scanf("%d", &ch2);
                                if(ch2==1)
                                {
                                        temp=start;
                                        start=start->next;
                                        free(temp);
                                        start->prev=NULL;
                                        printf("\nFirst node deleted! ");
                                }
                                else if(ch2==2)
                                {
                                        temp=last;
                                        last=last->prev;
                                        free(temp);
                                        last->next=NULL;
                                        printf("\nLast node deleted!" );
                                }
                                else if(ch2==3)
                                {
                                        printf("\nEnter the index: ");
                                        scanf("%d", &ind);
                                        struct node* temp1;
                                        temp1=start;
                                        for(i=1; i<ind; i++)
                                        {
                                                temp1=temp1->next;
                                        }
                                        temp=temp1->prev;
                                        temp->next=temp1->next;
                                        temp=temp1->next;
                                        temp->prev=temp1->prev;
                                        free(temp1);
                                        printf("\nNode deleted! ");
                                }
                        }
                }
                else if(ch==3)
                {
                        printf("\nThe list is: ");
                        temp=start;
                        if(start!=NULL)
                        {
                                while(temp!=NULL)
                                {
                                        printf("%d ", temp->data);
                                        temp=temp->next;
                                }
                        }
                }
                else if(ch==4)
                        return 0;
        }

        return 0;

}
