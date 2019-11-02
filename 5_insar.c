#include <stdio.h>

int main()
{
        int a[100], n, i, j, el, ch;
        printf("\nEnter the number of elements in the array: ");
        scanf("%d", &n);
        printf("\nEnter the elements in the array: ");
        for(i=0; i<n; i++)
                scanf("%d", &a[i]);
        printf("\nEnter the element to insert: ");
        scanf("%d", &el);
        printf("\nWhere do you want to insert the element?\n1. At the start\n2. At the End \n3. At a specified index\nYour choice: ");
        scanf("%d", &ch);
        if(ch==1)
        {
                for(i=n-1; i>=0; i--)
                {
                        a[i+1]=a[i];
                }
                n++;
                a[0]=el;
        }
        else if(ch==2)
        {
                a[n++]=el;
        }
        else if(ch==3)
        {
                int ind;
                printf("\nEnter the index to which the element is to be added: ");
                scanf("%d", &ind);
                for(i=n-1; i>=ind; i--)
                {
                        a[i+1]=a[i];
                }
                a[ind]=el;
                n++;
        }
        printf("\nElement has been inserted!\nThe array now is: ");
        for(i=0; i<n; i++)
                printf("%d ", a[i]);
        return 0;

}
