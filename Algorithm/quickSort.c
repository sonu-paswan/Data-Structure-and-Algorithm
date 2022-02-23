#include <stdio.h>
#include <stdlib.h>
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
int partition(int a[], int l, int h)
{
    int pivot = a[l];
    int i = l; // for traversing from left to right
    int j = h; // for traversing from right to left
    do
    {
        do{i++;}while(a[i]<=pivot);
        do{j--;}while(a[j]>pivot);
        if (i < j)
            swap(&a[i], &a[j]);
    } while (i < j);
    /* j provides the correct position for pivot element after above procedure */
    swap(&a[l], &a[j]); 
    return j;
}
// divide and conquer algorithm
void quicksort(int A[], int l, int h) 
{
    int j;
    if (l < h)
    {
        j = partition(A, l, h);
        quicksort(A, l, j);
        quicksort(A, j + 1, h);
    }
}

int main()
{   int h;
    // int arr[] = {4, 3, 1, 6, 8, 7, 77, 9, 2,6,34,78,23};
    scanf("%d",&h);
    int *arr=(int *)malloc(sizeof(int )*h);
    for(int i=0;i<h;i++)
    scanf("%d",&arr[i]);
    int low = 0;
    
    quicksort(arr, low, h);
    for (int i = 0; i < h; i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}

/* time complexity -> O(nlogn)
    */