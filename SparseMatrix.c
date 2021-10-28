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
                matrix2[1][k]=i+1; // stores position of row
                matrix2[2][k]=j+1; // stores position of coloum
                k++;
            }
        }
    }
    printf("row    : ");
    for(int r=0;r<size;r++){
        printf("%d ",matrix2[1][r]); // row
    }
    printf("\ncoloum : ");
    for(int c=0;c<size;c++){
        printf("%d ",matrix2[2][c]); // coloum
    }
    //// printing sparse matrix
    printf("\nvalue  : ");
    for(int v=0;v<size;v++){
        printf("%d ",matrix2[0][v]); // value
    }
    
    return 0;
}