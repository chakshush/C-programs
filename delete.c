#include<stdio.h>
void main()
{
  int a[10000],i,b,c;
  printf("Define array, no of elements \n");
  scanf("%d",&b);
  printf("Define array, enter the %d elements \n",b);
  for(i=0;i<b;i++) scanf("%d",&a[i]);
  printf("which element to delete? \n");
  scanf("%d",&c);
  for(i=c-1;i<b;i++) a[i]=a[i+1];
  printf("output \n");
  for(i=0;i<b-1;i++) printf("%d \n",a[i]);
}
