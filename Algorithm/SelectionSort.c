// selection sort program in c language
// 20/10/2021
#include <stdio.h>
#include <stdlib.h>
void swap(int *p, int *q) // swaping function
{
    int temp = *p;
    *p = *q;
    *q = temp;
}
void SelectionSort(int a[], int len)
{
    for (int i = 0; i < len - 1; i++)
    {
        int key = i;
        for (int j = i + 1; j < len; j++)
        {
            if (a[j] < a[key]) // finding smallest element index
                key = j;
        }
        swap(a + key, a + i);
    }
}
int main()
{
    printf("enter size of array : ");
    int size;
    scanf("%d", &size);
    int *arr = (int *)malloc(sizeof(int) * size); // dynamic array
    printf("enter elements :-\n");
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }
    SelectionSort(arr, size);
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}