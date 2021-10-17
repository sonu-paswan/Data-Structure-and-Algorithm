#include <stdio.h>
int array[50];
void merge(int a[], int l, int m, int h)
{   // merge algorithm

    int i, j, k = l;
    i = l;
    j = m + 1;
    while (i <= m && j <= h)
    {
        if (a[i] < a[j])
            array[k++] = a[i++];
        else
            array[k++] = a[j++];
    }
    if (j > h)
    {
        while (i <= m)
        {
            array[k++] = a[i++];
        }
    }
    else
    {
        while (j <= h)
        {
            array[k++] = a[j++];
        }
    }
    for (int m = l; m <= h; m++)
    {
        a[m] = array[m];
    }
}
void mergeSort(int a[],int left, int right){
    if(left<right){
        int mid=(left+right)/2;
        mergeSort(a,left,mid);
        mergeSort(a,mid+1,right);
        merge(a,left,mid,right);
    }
}
int main()
{
    int arr[]={4,5,2,1,8,9,-4,6,78};
    mergeSort(arr,0,8);
    for(int i=0;i<9;i++){
        printf("%d ",arr[i]);
    }
    return 0;
}