#include <stdio.h>
#include <stdlib.h>
//simple example of DMA in c language
int main()
{
    int n;
    printf("enter the number of elements :");
    scanf("%d", &n);
    int *ptr = calloc(n, sizeof(int)); //same as ptr=malloc(sizeof(int)*n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &ptr[i]);
    }
    printf("printing......\n");
    printf("base address of pointer : %x\n", ptr);
    for (int j = 0; j < n; j++)
    {
        printf("%d ", ptr[j]);
    }
    printf("\nhow many more memory you need : ");
    int m;
    scanf("%d", &m);
    ptr = realloc(ptr, (n + m) * sizeof(int));
    printf("enter new elements \n");
    for (int i = n; i < n + m; i++)
    {
        scanf("%d", &ptr[i]);
    }
    printf("printing updated elements......\n");
    printf("base address of pointer after realloc : %x\n", ptr);
    for (int k = 0; k < n + m; k++)
    {
        printf("%d ", ptr[k]);
    }
    free(ptr);
    return 0;
}
// note:->re-allocation of memory maintains the already present value
//  and new blocks will be initialized with the default garbage value.