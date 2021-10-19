#include <stdio.h>
// program to find factorial for bigger numbers
// 10/19/2021
#define MAX 500
int multiply(int, int[], int); // basic multiplication program

void factorial(int num)
{ // factorial program
    int arr[MAX];
    arr[0] = 1;
    int size = 1;
    for (int x = 2; x <= num; x++)
    {
        size = multiply(x, arr, size); //size should be updated
    }
    printf("factorial of %d = ", num);
    for (int i = size - 1; i >= 0; i--)
    {
        printf("%d", arr[i]);
    }
}
int multiply(int number, int array[], int size)
{
    ///  multiplication algorithm ///
    int carry = 0;
    for (int i = 0; i < size; i++)
    {
        int product = array[i] * number + carry;
        array[i] = product % 10;
        carry = product / 10;
    }
    while (carry != 0)
    { //after multiplication carry algorithm
        array[size] = carry % 10;
        carry = carry / 10;
        size++;
    }
    /////////////////////////////////
    return size;
}
int main()
{
    int num;
    printf("enter number for getting factorial :");
    scanf("%d", &num);
    factorial(num);
    return 0;
}

// reference  geeks for geeks