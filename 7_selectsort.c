#include <stdio.h>

int main()
{
        int a[100], n, i, j, t, small, smalli;
        printf("\nEnter the number of elements in the array: ");
        scanf("%d", &n);
        printf("\nEnter the elements in the array: ");
        for(i=0; i<n; i++)
                scanf("%d", &a[i]);
      
       int mini;
    for (i = 0; i < n-1; i++) 
    { 
        mini = i; 
        for (j = i+1; j < n; j++) 
          if (a[j] < a[mini]) 
            mini = j; 
  		t=a[mini];
  		a[mini]=a[i];
  		a[i]=t;
    } 
        printf("\nThe array has been sorted!\nThe array now is: ");
        for(i=0; i<n; i++)
                printf("%d ", a[i]);
        return 0;

}
