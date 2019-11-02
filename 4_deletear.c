#include <stdio.h>

int main()
{
        int a[100], n, i, j, el;
        printf("\nEnter the number of elements in the array: ");
        scanf("%d", &n);
        printf("\nEnter the elements in the array: ");
        for(i=0; i<n; i++)
                scanf("%d", &a[i]);
        printf("\nEnter the element to delete: ");
        scanf("%d", &el);
        for(i=0; i<n; i++)
        {
                if(a[i]==el)
                {
                        for(j=i; j<n-1; j++)
                        {
                                a[j]=a[j+1];
                        }
                        n--;
                }
        }
        printf("\nElement has been deleted!\nThe array now is: ");
        for(i=0; i<n; i++)
                printf("%d ", a[i]);
        return 0;

}
