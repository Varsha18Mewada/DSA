#include<stdio.h>
#include<stdlib.h>
void ins_heap(int [],int,int);
int main()
{
 int i,x,arr[5];
 for(i=0; i<5; i++){
    printf("Enter an element : ");
    scanf("%d",&x);
    ins_heap(arr,x,i);
 }
 printf(" \nFollowing is heap tree\n ");
 for(i=1; i<=5; i++){
    printf("%d\t",arr[i]);

 }
 return 0;
}
void ins_heap(int arr[],int x, int count){
    int ptr,par;
    count++;
    ptr=count;
    while(ptr>1){
        par=ptr/2;
        if(arr[par]>=x){
            arr[ptr]=x;
            return;
        }
        arr[ptr]=arr[par];
        ptr=par;
    }
    arr[1]=x;


}
