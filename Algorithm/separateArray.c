#include <stdio.h>
#include <stdlib.h>
//problem separate negative numbers in one side of array and positive numbers in another side

int *fun(int *p, int len)
{
    int *pointer=(int*)malloc(sizeof(int)*len);
    int j;
    for(int i=0;i<len;i++){
        if(p[i]<0){
            pointer[j++]=p[i];
        }
    }
    for(int k=0;k<len;k++){
        if(p[k]>=0){
            pointer[j++]=p[k];
        }
    }
    return pointer;
}
int main()
{
    int count = 0;
    printf("enter number of element \n");
    scanf("%d",&count);
    int *ptr = (int *)malloc(sizeof(int) * count);
    printf("enter numbers \n");
    for (int i = 0; i < count; i++)
    {
        scanf("%d", &ptr[i]);
    }
    int *newptr = fun(ptr, count);
    for(int j=0;j<count;j++){
        printf("%d ",newptr[j]);
    }
    return 0;
}