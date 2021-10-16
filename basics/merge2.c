#include <stdio.h>
#include <stdlib.h>
int array[50];
// program to merge in a single array considering two lists
void merge(int a[], int l, int m, int h)
{

    int i, j, k = 0;
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
int main()
{
    int arr[] = {6, 7, 8, 9, 11, 2, 3, 4, 5};
    int len = sizeof(arr) / sizeof(arr[0]);
    int low = 0;
    int high = len - 1;
    int mid = (low + high) / 2;
    merge(arr, low, mid, high);
    for (int i = 0; i < len; i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}
// note: - condition is that the two list at either side of array middle elements must be sorted