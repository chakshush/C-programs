#include <stdio.h>
#include<stdlib.h>
struct stack
{
        int data;
        struct stack *next;
};
int main()
{
        int n, i, ch, ind;
        struct stack *temp=NULL, *start=NULL, *top=NULL;
        while(ch!=4)
        {
                printf("\nWhat operation would you like to do? \n1. Push\n2. Pop\n3. Traverse\nYour choice: ");
                scanf("%d", &ch);
                if(ch==1)
                {
                        temp=(struct stack*)malloc(sizeof(struct stack*));
                        printf("\nEnter the data: ");
                        scanf("%d", &temp->data);
                        temp->next=NULL;
                        if(start==NULL)
                                start=top=temp;
                        else
                        {
                                top->next=temp;
                                top=temp;
                        }
                        printf("\nThe node has been pushed to the stack! ");
                }
                else if(ch==2)
                {
                        if (start==NULL)
                                printf("\nUnderflow! ");
                        else
                        {
                                temp=start;
                                while(temp->next!=top)
                                        temp=temp->next;
                                free(top);
                                top=temp;
                                top->next=NULL;
                                printf("\nTop element has been popped!");
                        }
                }
                else if(ch==3)
                {
                        temp=start;
                        printf("\nThe stack now is: ");
                        while(temp!=NULL)
                        {
                                printf("%d ", temp->data);
                                temp=temp->next;
                        }
                }
        }
        return 0;

}
