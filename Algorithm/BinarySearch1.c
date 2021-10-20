// binary search program in c language
// 20/10/2021
#include <stdio.h>
int Bsearch(int a[],int size,int key){
    int x=-1,l=0,h=size-1;
    int mid;
    // binary search algorithm
    while(l<=h){
        mid=(l+h)/2;
        if(key>a[mid])
        l=mid+1;
        else if(key<a[mid])
        h=mid-1;
        else
        return mid; //for equal condition
    }
    return x;
}
int main()
{
    int arr[]={2,3,6,8,10,19};
    int len=sizeof(arr)/sizeof(arr[0]);
    int result=Bsearch(arr,len,3);
    printf("number located at %d",result);
    return 0;
}
// binary search works on sorted array