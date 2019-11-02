#include<stdio.h>
void swap(int *a,int *b){
  int h=*a;
  *a=*b;
  *b=h;
}
int partition (int a[],int l,int h) {
    int p=a[h];
    int i=(l-1);
    for(int j=l;j<=h-1;j++) {
        if (a[j]<=p){
            i++;
            swap(&a[i],&a[j]);
        }
    }
    swap(&a[i+1],&a[h]);
    return (i+1);
}
void quickSort(int a[],int l,int h) {
    if (l<h){
        int p=partition(a,l,h);
        quickSort(a,l,p-1);
        quickSort(a,p+1,h);
    }
}
int main() {
    int a[10000],i,n;
    scanf("%d",&n);
    for(i=0;i<n;i++) scanf("%d ",&a[i]);
    quickSort(a,0,n-1);
    for (i=0;i<n;i++) printf("%d ",a[i]);
    printf(" \n");
    return 0;
}
