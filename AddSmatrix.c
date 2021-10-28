
// sparse matrix addition in c language
//  28/10/2021

#include <stdio.h>
void getSmatrix(int arr[10][3])
{
	int row, colomn, nonzero;
	printf("enter rows and column of matrix\n");
	scanf("%d %d", &row, &colomn);
	printf("enter number of non zero elements :");
	scanf("%d", &nonzero);
	arr[0][0] = row;
	arr[0][1] = colomn;
	arr[0][2] = nonzero;
	for (int i = 1; i <= nonzero; i++)
	{
		printf("enter row , colomn and value\n");
		scanf("%d %d %d", &arr[i][0], &arr[i][1], &arr[i][2]);
	}
}
void print(int arr[10][3])
{
	int s = arr[0][2];
	if (s == 0) 
	{
		printf("matrix not found \n");
		return;
	}
	printf("printing matrix \n");
	for (int i = 1; i <= s; i++)
	{
		printf("%d\t%d\t%d\n", arr[i][0], arr[i][1], arr[i][2]);
	}
}
void addSmatrix(int A[10][3], int B[10][3], int C[10][3])
{
	C[0][2] = 0; // initial values in C matrix i.e 0
	if (A[0][0] != B[0][0] || A[0][1] != B[0][1])
	{
		printf("dimensions are not same\n");
		return;
	}
	int i = 1, j = 1, k = 1;
	C[0][0] = A[0][0]; // rows 
	C[0][1] = A[0][1]; // colomns 

	int m = A[0][2];
	int n = B[0][2];
	
	while (i <=m && j <=n)
	{
		if (A[i][0] < B[j][0]) // unequal row condition
		{
			C[k][0] = A[i][0];
			C[k][1] = A[i][1];
			C[k][2] = A[i][2];
			k++;
			i++;
		}
		else if (B[j][0] < A[i][0]) // unequal row condition
		{
			C[k][0] = B[j][0];
			C[k][1] = B[j][1];
			C[k][2] = B[j][2];
			k++;
			j++;
		}
// after that we check for same row but different colomns condition
		else if(A[i][0]==B[j][0])
		{
			if (A[i][1] < B[j][1]) // unequal colomns
			{
				C[k][0] = A[i][0];
				C[k][1] = A[i][1];
				C[k][2] = A[i][2];
				k++;
				i++;
			}
			else if (B[j][1] < A[i][1]) // unequal colomns
			{
				C[k][0] = B[j][0];
				C[k][1] = B[j][1];
				C[k][2] = B[j][2];
				k++;
				j++;
			}
			else 
			{	// in this condition we have same row and colomn
				C[k][0] = A[i][0];
				C[k][1] = A[i][1];
				C[k][2] = A[i][2] + B[j][2];
				k++;
				i++;
				j++;
			}
			
		}
		
	}
	while (i <= m) // remaining elements of A matrix
	{
		C[k][0] = A[i][0];
		C[k][1] = A[i][1];
		C[k][2] = A[i][2];
		k++;
		i++;
	}
	while (j <= n) // remaining elements of B matrix 
	{
		C[k][0] = B[j][0];
		C[k][1] = B[j][1];
		C[k][2] = B[j][2];
		k++;
		j++;
	}
	C[0][2] = k - 1; // updating the number of non zero in new added matrix
}
int main()
{
	int A[10][3], B[10][3], C[10][3];
	getSmatrix(A);
	printf("for A\n");
	print(A);
	getSmatrix(B);
	printf("for B\n");
	print(B);
	addSmatrix(A, B, C);
	printf("for A+B \n");
	print(C);
	return 0;
}