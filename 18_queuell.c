#include <stdio.h>
#include<stdlib.h>
struct queue
{
        int data;
        struct queue *next;
};
int main()
{
        int n, i, ch, ind;
        struct queue *temp=NULL, *front=NULL, *rear=NULL;
        while(ch!=4)
        {
                printf("\nWhat operation would you like to do? \n1. Enqueue\n2. Dequeue\n3. Traverse\nYour choice: ");
                scanf("%d", &ch);
                if(ch==1)
                {
                        temp=(struct queue*)malloc(sizeof(struct queue*));
                        printf("\nEnter the data: ");
                        scanf("%d", &temp->data);
                        temp->next=NULL;
                        if(front==NULL)
                                front=rear=temp;
                        else
                        {
                                rear->next=temp;
                                rear=temp;
                        }
                        printf("\nThe node has been added to the queue! ");
                }
                else if(ch==2)
                {
                        if (front==NULL)
                                printf("\nUnderflow! ");
                        else
                        {
                                if(rear==front)
                                {
                                        free(rear);
                                        rear=front=NULL;
                                }
                                else
                                {
                                        temp=front;
                                        front=front->next;
                                        free(temp);
                                        printf("\nDeletion successful!");
                                }
                        }
                }
                else if(ch==3)
                {
                        temp=front;
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
