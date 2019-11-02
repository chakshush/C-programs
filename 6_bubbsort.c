#include <stdio.h>

int main()
{
        int a[100], n, i, j, t, small, smalli;
        printf("\nEnter the number of elements in the array: ");
        scanf("%d", &n);
        printf("\nEnter the elements in the array: ");
        for(i=0; i<n; i++)
                scanf("%d", &a[i]);
        for(i=0; i<n-1; i++)
        {
                small=a[i];
                smalli=i;
                for(j=i+1; j<n; j++)
                {
                        if(small>a[j])
                        {
                                smalli=j;
                                small=a[j];
                        }
                }
                t=a[i];
                a[i]=a[smalli];
                a[smalli]=t;
        }
        printf("\nThe array has been sorted!\nThe array now is: ");
        for(i=0; i<n; i++)
                printf("%d ", a[i]);
        return 0;

}
