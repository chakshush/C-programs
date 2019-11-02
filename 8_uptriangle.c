#include <stdio.h>

int main()
{
        int a[100][100], m, n, i, j;
        printf("\nEnter the number of rows in the array: ");
        scanf("%d", &m);
        printf("\nEnter the number of columns in the array: ");
        scanf("%d", &n);
        printf("\nEnter the elements in the array: ");
        for(i=0; i<m; i++)
        {
                for(j=0; j<n; j++)
                {
                        scanf("%d", &a[i][j]);
                }
        }
        if(m!=n)
        {
                printf("\nCannot show upper triangle of the matrix. Exiting");
                return 0;
        }
        else
        {
                printf("\nThe upper half of the matrix is: \n");
                for(i=0; i<m; i++)
                {
                        for(j=0; j<n; j++)
                        {
                                if(i<=j)
                                {
                                        printf("%d ", a[i][j]);
                                }
                        }
                        printf("\n");
                }

        }
        return 0;

}
