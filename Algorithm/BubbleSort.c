// Bubble sort program in c language
//10/20/2021
#include <stdio.h>
#include <stdlib.h>
void swap(int *a,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}
void BubbleSort(int arr[],int size){
    int indicator;
    for(int i=0;i<size-1;i++){
        indicator=0;
        for(int j=0;j<size-1-i;j++){
            if(arr[j]>arr[j+1]){
                swap(arr+j,arr+j+1);
                indicator=1;
            }
            
        }
        if(indicator==0){
                return;
            }
    }
}
int main()
{
    int len;
    printf("enter size of array : ");
    scanf("%d",&len);
    int *array=(int*)malloc(sizeof(int)*len);
    printf("enter elements :-\n");
    for(int j=0;j<len;j++){
        scanf("%d",&array[j]);
    }
    BubbleSort(array,len);
    for(int i=0;i<len;i++){
        printf("%d ",array[i]);
    }
    return 0;
}