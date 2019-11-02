#include<stdio.h>
void main()
{
 int a[100000],b,c,i;
 printf("Define array, no of elements \n");
 scanf("%d",&b);
 printf("Define array, enter the %d elements \n",b);
 for(i=0;i<b;i++) scanf("%d",&a[i]);
 printf("what to search for? \n");
 scanf("%d",&c);
 for(i=0;i<b;i++)
 {
   if(a[i]==c)
   {
     printf("Value exists at %dth location. \n",i+1);
     break;
   }
 } 
 if(i==b) printf("Value does not exist \n");
}
