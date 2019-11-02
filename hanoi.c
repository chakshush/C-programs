#include <stdio.h>
int n,s=0;
void steps(int n,int f,int t,int a){
    if (n==1){
      printf("Move disk 1 from rod %d to rod %d \n", f, t);
      s++;
      return;
    }
    steps(n-1,f,a,t);
    printf("Move disk %d from rod %d to rod %d \n",n,f,t);
    s++;
    steps(n-1,a,t,f);
}
int main(){
    scanf("%d",&n);
    steps(n,1,2,3);
    printf("no. of steps :- %d \n",s);
}
