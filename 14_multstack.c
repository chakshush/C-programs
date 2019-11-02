#include <stdio.h>

int main()
{
        int mstack[25];
        int top1, top2;
        top1=-1;
        top2=25;
        int el;
        int i;
        int ch=-1;
        while(ch!=7)
        {
                printf("\n\nWhat operation would you like to do? \n1. Push to stack 1 \n2. Pop from stack 1\n3. Push to stack 2");
                printf("\n4. Pop from stack 2\n5. Traverse stack 1\n6. Traverse stack 2\n7. Exit program\nYour choice: ");
                scanf("%d", &ch);
                if(ch==1)
                {
                        if(top1==(top2-1))
                        {
                                printf("\nOverflow! ");
                        }
                        else
                        {
                                printf("\nEnter the element to add: ");
                                scanf("%d", &el);
                                mstack[++top1]=el;
                                printf("\nElement added! ");
                        }
                }
                else if(ch==2)
                {
                        if(top1==-1)
                        {
                                printf("\nUnderflow! ");
                        }
                        else
                        {
                                top1--;
                                printf("\nElement popped! ");
                        }
                }
                else if(ch==3)
                {
                        if(top1==(top2-1))
                        {
                                printf("\nOverflow! ");
                        }
                        else
                        {
                                printf("\nEnter the element to add: ");
                                scanf("%d", &el);
                                mstack[--top2]=el;
                                printf("\nElement added! ");
                        }
                }
                else if(ch==4)
                {
                        if(top2==25)
                        {
                                printf("\nUnderflow! ");
                        }
                        else
                        {
                                top1++;
                                printf("\nElement popped! ");
                        }
                }
                else if(ch==5)
                {
                        printf("\nThe elements in stack 1 are: ");
                        for(i=0; i<=top1; i++)
                                printf("%d ", mstack[i]);
                }
                else if(ch==6)
                {
                        printf("\nThe elements in stack 2 are: ");
                        for(i=24; i>=top2; i--)
                                printf("%d ", mstack[i]);
                }
                else if(ch==7)
                {
                        return 0;
                }
        }
        return 0;

}
