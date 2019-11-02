#include <stdio.h>
struct bucket{
    int count;
    int* value;
};
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
void bucketSort(int array[],int n){
    struct bucket bs[3];
    int i,j,k;
    for(i=0;i<3;i++){
        bs[i].count=0;
        bs[i].value=(int*)malloc(sizeof(int)*n);
    }
    for(i=0;i<n;i++){
        if(array[i]<0) bs[0].value[bs[0].count++]=array[i];
        else if(array[i]>10) bs[2].value[bs[2].count++] = array[i];
        else bs[1].value[bs[1].count++] = array[i];
    }
    for(k=0,i=0;i<3;i++){
        quickSort(bs[i].value,0,bs[i].count-1);
        for(j=0;j<bs[i].count;j++) array[k+j]=bs[i].value[j];
        k+=bs[i].count;
        free(bs[i].value);
    }
}
int main(){
    int array[100],j,n;
    printf("Size of array?: ");
    scanf("%d",&n);
    for(j=0;j<n;j++) scanf("%d",&array[j]);
    printf("Before Sorting\n");
    for (j = 0; j<n; j++) printf("%d ", array[j]);
    bucketSort(array, n);
    printf("\n After Sorting\n");
    for (j = 0; j<n; j++) printf("%d ", array[j]);
    return 0;
}
