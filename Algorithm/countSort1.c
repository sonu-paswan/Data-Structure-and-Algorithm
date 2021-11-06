#include <stdio.h>
#include <stdlib.h>
// count sort for positive numbers only
// 06/11/2021
void CountSort(int a[], int size)
{
    int max = a[0];
    for (int i = 1; i < size; i++) /*finding max element*/
    {
        if (max < a[i])
            max = a[i];
    }
    int *count = (int *)malloc(sizeof(int) * (max + 1));
    for (int i = 0; i <= max; i++)
    {
        count[i] = 0;/*making all elements of count array initialy zero*/
    }
    for (int j = 0; j < size; j++)
    {
        count[a[j]]++;/*storing the count of elements*/
    }
    int k = 0, j = 0;
    /*k for a traversal and j for count traversal*/
    while (j <= max)
    {
        if (count[j])
        {
            a[k] = j;
            k++;
            count[j]--;
        }
        else
        {
            j++;
        }
    }
    free(count);
}
int main()
{
    int arr[] = {2, 3, 4, 1, 5, 3};
    int len = sizeof(arr) / sizeof(arr[0]);
    CountSort(arr, len);
    for (int i = 0; i < len; i++)
        printf("%d ", arr[i]);
    return 0;
}