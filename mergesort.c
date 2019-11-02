#include <stdio.h>

void merge(int a[25], int first, int last)
{
        int mid=(first+last)/2;
        int b[25], bi=0;
        int i=first, j=mid+1;
        while(i<=mid && j<=last)
        {
                if(a[i]>a[j])
                        b[bi++]=a[j++];
                else if(a[i]<a[j])
                        b[bi++]=a[i++];
                else if(a[i]==a[j])
                {
                        b[bi++]=a[j++];
                        b[bi++]=a[i++];
                }
        }
        if(i>mid)
        {
                while(j<=last)
                        b[bi++]=a[j++];
        }
        if(j>last)
        {
                while(i<=mid)
                        b[bi++]=a[i++];
        }
        i=first; bi=0;
        while(i<=last)
                a[i++]=b[bi++];

}
void mergesort(int a[25], int first, int last)
{
        int mid;
        if(first < last)
        {
                mid=(first+last)/2;
                mergesort(a, mid+1, last);
                mergesort(a, first, mid);
                merge(a, first, last);
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
        mergesort(a, 0, n-1);
        printf("\nThe sorted array now is: ");
        for(i=0; i<n; i++)
                printf("%d ", a[i]);

        return 0;

}
