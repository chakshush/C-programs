#include<stdio.h>
void main(){
  int a[1000][1000],b[1000][3],i,j,c,d,e=0;
  printf("Input no. of rows and columns for input sparse matrix: \n");
  scanf("%d %d",&c,&d);
  for(i=0;i<c;i++){
    for(j=0;j<d;j++) scanf("%d ",&a[i][j]);
  }
  for(i=0;i<c*d;i++){
    for(j=0;j<d;j++){
      if(a[i][j]!=0) {
        (b[e][0]=i);
        (b[e][1]=j);
        (b[e][2]=a[i][j]);
        e++;
      }
    }
  }
  printf("r c v \n");
  for(i=0;i<e;i++) printf("%d %d %d \n",b[i][0],b[i][1],b[i][2]);
}
