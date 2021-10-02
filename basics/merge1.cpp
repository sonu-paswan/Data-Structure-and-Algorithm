#include <iostream>
#include <algorithm>
using namespace std;
//program to merge two sorted list to another list
void func(int A[],int B[],int C[],int m, int n)
{
    int i=0,j=0,k=0;
    //merging algorithm
    while(i<m && j<n)
    {
        if(A[i]<B[j])
        C[k++]=A[i++];
        else 
        C[k++]=B[j++];
    }
    while(i<m)
    {
        C[k++]=A[i++];
    }
    while(j<n)
    {
        C[k++]=B[j++];
    }
}
int main()
{   int arr1[]={200};
    int a=sizeof(arr1)/sizeof(arr1[0]);
    int arr2[]={34};
    int b=sizeof(arr2)/sizeof(arr2[0]);
    // sort(arr1,arr1+a);
    // sort(arr2,arr2+b);
    int arr3[a+b];
    func(arr1,arr2,arr3,a,b);
    for(int k=0;k<a+b;k++)
    {
        cout<<arr3[k]<<" ";
    }
    
    return 0;
}