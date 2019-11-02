#include <stdio.h>
int main()
{
        int ch=-1, queue[100], front=-1, rear=-1;
        int el;
        while(ch!=4)
        {
                printf("\nWhat operation would you like to do? \n1. Enqueue\n2. Dequeue\n3. Traverse\n4. Exit\nYour choice: ");
                scanf("%d", &ch);
                if(ch==1)
                {
                        if(rear==99)
                        {
                                printf("\nOverflow! ");
                        }
                        else
                        {
                                printf("\nEnter the element that you would like to enqueue: ");
                                scanf("%d", &el);
                                if(front==-1)
                                        front++;
                                queue[++rear]=el;
                        }
                }
                else if(ch==2)
                {
                        if(front==-1)
                        {
                                printf("\nUnderflow! ");
                        }
                        else if(front==rear)
                        {
                                front=-1;
                                rear=-1;
                        }
                        else
                        {
                                front++;
                        }
                }
                else if(ch==3)
                {
                        int i;
                        printf("\nThe Queue is: ");
                        if (front!=-1)
                        {
                                for(i=front; i<=rear; i++)
                                {
                                        printf("%d ", queue[i]);
                                }
                        }
                }
                else if(ch==4)
                {
                        return 0;
                }
        }
        return 0;

}
