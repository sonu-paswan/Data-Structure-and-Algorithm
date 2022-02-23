// recursive function to find max and min in array 

#include <iostream>
using namespace std;
int Max(int a[], int i, int j)
{
    int max1,max2,max;
    if (i == j)
        return a[i];
    else if(i==j-1){
        if(a[i]>a[j])
        return a[i];
        else
        return a[j];
    }
    else{
        int mid=(i+j)/2;
        max1=Max(a,i,mid);
        max2=Max(a,mid+1,j);
        if(max1>max2)
        max=max1;
        else max=max2;
    }
    return max;
}
int Min(int a[], int i, int j)
{
    int min1,min2,min;
    if (i == j)
        return a[i];
    else if(i==j-1){
        if(a[i]>a[j])
        return a[j];
        else
        return a[i];
    }
    else{
        int mid=(i+j)/2;
        min1=Min(a,i,mid);
        min2=Min(a,mid+1,j);
        if(min1>min2)
        min=min2;
        else min=min1;
    }
    return min;
}
int main()
{
    int arr[] = {34, 23, 1, 4, 567, 89, 8, 7, 9, 25, 670};
    printf("%d\n",Max(arr, 0, 10));
    printf("%d",Min(arr, 0, 10));
    return 0;
}