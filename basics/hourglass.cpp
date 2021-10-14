#include <iostream>
#include <limits>
///  HourGlass problem from hacker rank 
/// solved on 14/10/2021
using namespace std;
int MAX(int array[],int  len){ // max integer finder
    int a=array[0];
    for(int i=0;i<len;i++){
        if(array[i]>a){
            a=array[i];
        }
    }
    return a;

}
int main()
{   int arr[6][6],store[16];
    printf("enter elements in 6X6 matrix\n");
    for(int i=0;i<6;i++){  //taking elements of 2 D array
        for(int j=0;j<6;j++){
            scanf("%d",&arr[i][j]);
        }
    }
    printf("entered elements \n"); // printing elements of 2 D elements
    for(int i=0;i<6;i++){
        for(int j=0;j<6;j++){
            printf("%3d  ",arr[i][j]);
        }
        printf("\n");
    }int k=0;
    for(int m=0;m<4;m++){  // main algorithm of program
        for(int n=0;n<4;n++){
            store[k]=arr[m][n]+arr[m][n+1]+arr[m][n+2]+arr[m+1][n+1]+arr[m+2][n]+arr[m+2][n+1]+arr[m+2][n+2];
            
            k++;
        }
        // printf("\n");
    }
    int result=MAX(store,16); 
    printf("final result=%d",result);
    return 0;
}