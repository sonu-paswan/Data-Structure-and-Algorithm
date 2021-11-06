#include <stdio.h>
#include <stdlib.h>
// count sort for negative numbers 
// 06/11/2021
void CountSort2(int a[], int size)
{
    int max = a[0];
    for (int i = 0; i < size; i++)
    {
        if (a[i] > max)
            max = a[i];
    }
    int min = a[0];
    for (int j = 0; j < size; j++)
    {
        if (a[j] < min)
            min = a[j];
    }
    int range = max - min + 1;
    int *count = (int *)malloc(sizeof(int) * (range+1));
    for (int i = 0; i <= range; i++)
    {
        count[i] = 0; /*making all elements of count array initialy zero*/
    }
    for (int j = 0; j < size; j++)
    {
        count[a[j] - min]++;
    }
    int k = 0, j = 0;
    while (j <= range)
    {
        if (count[j])
        {
            a[k] = j + min;
            k++;
            count[j]--;/* important to decrement*/
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
    int arr[] = {2, 3, 4, 1, 5, 3,-1,-5,23};
    int len = sizeof(arr) / sizeof(arr[0]);
    CountSort2(arr, len);
    for (int i = 0; i < len; i++)
        printf("%d ", arr[i]);
    return 0;
}