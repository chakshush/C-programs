#include <stdio.h>
int main()
{
        int ch=-1, stack[100], top=-1; int el;
        while(ch!=4)
        {
                printf("\nWhat operation would you like to do? \n1. Push\n2. Pop\n3. Traverse\n4. Exit\nYour choice: ");
                scanf("%d", &ch);
                if(ch==1)
                {
                        if(top==99)
                        {
                                printf("\nOverflow!");
                        }
                        else
                        {
                                printf("\nEnter the element to push: ");
                                scanf("%d", &el);
                                stack[++top]=el;
                        }
                }
                else if(ch==2)
                {
                        if(top==-1)
                        {
                                printf("\nUnderflow! ");
                        }
                        else
                        {
                                top--;
                        }
                }
                else if(ch==3)
                {
                        int i;
                        printf("\nThe stack is: ");
                        for(i=0; i<=top; i++)
                        {
                                printf("%d ", stack[i]);
                        }
                }
                else if(ch==4)
                {
                        return 0;
                }
        }
        return 0;

}
