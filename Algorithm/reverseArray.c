#include <stdio.h>
void reverse(int arr[], int start, int end)
{
    // int i = 0;
    while (start < end)
    {
        int temp = arr[start];
        arr[start]=arr[end];
        arr[end]=temp;
        start++;
        end--;
        
    }
    // time complexity->O(n)
}
// recursive method
void Rreverse(int arr[],int start,int end){
    if(start>=end){
        return ;
    }
    else{
        int temp=arr[start];
        arr[start]=arr[end];
        arr[end]=temp;
        Rreverse(arr,start+1,end-1);
    }
    // time complexiy->O(n)
}
int main()
{
    int arr[] = {3, 24, 5, 6, 1, 78, 9, 4};
    int len = sizeof(arr) / sizeof(arr[0]);
    Rreverse(arr, 0, len - 1);
    // printing
    for (int i = 0; i < len; i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}