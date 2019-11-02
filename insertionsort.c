#include <stdio.h>
void insertsort(int a[25], int n)
{
        int i, j, key;
        for(i=1; i<n; i++)
        {
                j=i-1;
                key=a[j+1];
                while(j>=0 && a[j]>key)
                {
                        a[j+1]=a[j];
                        j--;
                }
                a[j+1]=key;
        }
}
int main()
{
        int n, a[25], i;
        printf("\nEnter the number of elements in the array: ");
        scanf("%d", &n);
        printf("\nEnter the elements in the array: ");
        for(i=0; i<n; i++)
                scanf("%d", &a[i]);
        insertsort(a, n);
        printf("\nThe sorted array now is: ");
        for(i=0; i<n; i++)
                printf("%d ", a[i]);
        return 0;

}
