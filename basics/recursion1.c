#include <stdio.h>
long long factorial(int n)
{
    if(n==1)
    return n;
    else
    return n*factorial(n-1);
}
long long main()
{
    int num;
    printf("enter number for factorial: ");
    scanf("%d",&num);
    long long result =factorial(num);
    printf("factorial of %d is %lli\n",num,result);
    return 0;
}