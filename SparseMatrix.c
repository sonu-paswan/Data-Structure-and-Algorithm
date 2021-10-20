// sparse matrix 
// 20/10/2021
#include <stdio.h>

int main()
{
    int row=4,coloum=5;
    int matrix[4][5]=
    {
        {2 , 0 , 0 , 0 , 4 },
        {0 , 0 , 5 , 7 , 0 },
        {9 , 0 , 3 , 0 , 0 },
        {0 , 2 , 0 , 0 , 8 }
    };
    int size=0;
    for(int i=0;i<row;i++){
        for(int j=0;j<coloum;j++){
            if(matrix[i][j])
            {
                size++; // storing coloum size of sparse matrix
            }
        }
    }
    int matrix2[3][size];
    int k=0;
    for(int i=0;i<row;i++){
        for(int j=0;j<coloum;j++){
            if(matrix[i][j]){
                matrix2[0][k]=matrix[i][j]; // stores value
                matrix2[1][k]=i; // stores position of row
                matrix2[2][k]=j; // stores position of coloum
                k++;
            }
        }
    }
    //// printing sparse matrix
    for(int i=0;i<3;i++){
        for(int j=0;j<size;j++){
            printf("%d ",matrix2[i][j]);
        }
        printf("\n");
    }
    return 0;
}