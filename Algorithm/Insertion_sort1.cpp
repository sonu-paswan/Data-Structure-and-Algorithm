#include <iostream>
using namespace std;
void InsertionSort(int A[], int size)
{
    for (int i = 1; i < size; i++)
    {
        int key = A[i];
        int j = i - 1;
        while (j >= 0 && key < A[j])
        {
            A[j + 1] = A[j];
            j--;
        }
        A[j + 1] = key;
    }
}
int main()
{
    int arr[] = {23, 45, 2, 21, 78, -9, 67, 40, 20, 34, 77, 907, 45};
    int size = sizeof(arr) / sizeof(arr[0]);
    InsertionSort(arr, size);
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}
// insertion sort is good for small inputs or it can be also used to sort partially sorted list