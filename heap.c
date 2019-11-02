#include <stdio.h>
#include <stdlib.h>
struct heap{
    int size;
    int* a;
};
void swap(int* c,int* b){
  int t=*c;
  *c=*b;
  *b=t;
}
void max(struct heap* maxHeap,int idx){
    int largest=idx;
    int left=(idx<<1)+1;
    int right=(idx+1)<<1;
    if(left<maxHeap->size&&maxHeap->a[left]>maxHeap->a[largest]) largest=left;
    if(right<maxHeap->size&&maxHeap->a[right]>maxHeap->a[largest]) largest=right;
    if(largest!=idx){
        swap(&maxHeap->a[largest],&maxHeap->a[idx]);
        max(maxHeap,largest);
    }
}
struct heap* create(int *a,int size){
    int i;
    struct heap* maxHeap=(struct heap*)malloc(sizeof(struct heap));
    maxHeap->size=size;
    maxHeap->a=a;
    for(i=(maxHeap->size-2)/2;i>=0;--i) max(maxHeap,i);
    return maxHeap;
}
void heapSort(int* a,int size){
    struct heap* maxHeap=create(a,size);
    while(maxHeap->size>1){
        swap(&maxHeap->a[0],&maxHeap->a[maxHeap->size-1]);
        --maxHeap->size;
        max(maxHeap,0);
    }
}
void print(int* arr,int size){
    int i;
    for(i=0;i<size;++i) printf("%d ",arr[i]);
}
int main(){
    int n,a[10000];
    printf("array size?: ");
    scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%d ",&a[i]);
    heapSort(a,n);
    printf("\nSorted array is \n");
    print(a,n);
    return 0;
}
