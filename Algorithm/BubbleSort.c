// Bubble sort program in c language
//10/20/2021
#include <stdio.h>
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
    int array[]={4,7,6,8,10,2,1,15};
    int len=sizeof(array)/sizeof(array[0]);
    BubbleSort(array,len);
    for(int i=0;i<len;i++){
        printf("%d ",array[i]);
    }
    return 0;
}