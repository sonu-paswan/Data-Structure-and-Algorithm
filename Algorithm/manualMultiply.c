// program to multiply to numbers manually as we done in school days
// 19/10/2021
#include <stdio.h>

int main()
{
    int num1=9456;
    int num2=36;
    int product,carry=0,i,j=0;
    int arr[10];
    while(num1){
        arr[j++]=num1%10;
        num1/=10;
    }
    for( i=0;i<j;i++){  // multiply algorithm
        product=arr[i]*num2+carry;
        arr[i]=product%10;
        carry=product/10;
    }
    while(carry){ //remaining carries
        arr[i]=carry%10;
        carry=carry/10;;
        i++;
    }
    for(int j=i-1;j>=0;j--){
        printf("%d",arr[j]);
    }
    return 0;
}