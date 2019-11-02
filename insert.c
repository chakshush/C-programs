#include<stdio.h>
void main()
{
  int a[10000],i,b,c;
  printf("Define array, no of elements \n");
  scanf("%d",&b);
  printf("Define array, enter the %d elements \n",b);
  for(i=0;i<b;i++) scanf("%d",&a[i]);
  printf("where to insert the element? \n");
  scanf("%d",&c);
  for(i=b;i>=c;i--) a[i]=a[i-1];
  printf("Enter the element to insert. \n");
  scanf("%d",&a[c-1]);
  printf("output \n");
  for(i=0;i<=b;i++) printf("%d \n",a[i]);
}
