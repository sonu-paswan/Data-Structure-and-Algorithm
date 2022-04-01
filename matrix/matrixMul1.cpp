#include <iostream>
using namespace std;
// 4X4 matrix multiplication
int * mul(int *A,int *B,int n){
    // strassen's algorithm
    // int p=(A[0][0] +A[1][1])*(B[0][0]+B[1][1]);
    int p=(*(A+0+0) + *(A+1*n +1))*(*(B+0+0) + *(B+1*n+1));
    // int q=(A[1][0]+A[1][1])*B[0][0];
    int q=(*(A+1*n +0) + *(A+1*n+1))*(*(B+0+0));
    // int r=A[0][0]*(B[0][1]-B[1][1]);
    int r=(*(A+0+0) )*(*(B+0+1) - *(B+1*n+1));
    // int s=A[1][1]*(B[1][0]-B[0][0]);
    int s=(*(A+1*n+1))*(*(B+1*n+0)-*(B+0+0));
    // int t=(A[0][0]+A[0][1])*B[1][1];
    int t=(*(A+0+0) + *(A+0+1))*(*(B+1*n+1));
    // int u=(A[1][0]-A[0][0])*(B[0][0]+B[0][1]);
    int u=(*(A+1*n+0) - *(A+0 +0))*(*(B+0+0) + *(B+0+1));
    // int v=(A[0][1]-A[1][1])*(B[1][0]+B[1][1]);
    int v=(*(A+0+1) - *(A+1*n +1))*(*(B+1*n+0) + *(B+1*n+1));

    // c matrix 
    int *C= new int [n*n];
    *(C+0*n +0)=p+s-t+v;
    *(C+0*n +1)=r+t;
    *(C+1*n +0)=q+s;
    *(C+1*n +1)=p+r-q+u;
    return C;
}
int * add(int *A,int *B,int n)
{
    int *C= new int [n*n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            *(C + i*n +j)=*(A + i*n +j) + *(B + i*n +j);// *(A + i*n +j)
        }
    }
    return C;
}
int * sub(int *A,int *B,int n)
{
    int *C= new int [n*n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            *(C + i*n +j)=*(A + i*n +j) - *(B + i*n +j);
        }
    }
    return C;
}

int main()
{   
    int n=4;
    // cin>>n;
    int a[n][n],b[n][n],c[n][n];
    cout<<"enter matrix A\n";
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>a[i][j];
        }
    }
    cout<<"enter matrix B\n";
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>b[i][j];
        }
    }
    // displaying matrix 
    cout<<"matrix A is \n";
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<a[i][j]<<" ";
        }cout<<endl;
    }
    cout<<"matrix B is \n";
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<b[i][j]<<" ";
        }cout<<endl;
    }
    int *A11=new int[2*2],*A12=new int[2*2],*A21=new int[2*2],*A22=new int[2*2];
    int *B11=new int[2*2],*B12=new int[2*2],*B21=new int[2*2],*B22=new int[2*2];

    // spliting matrix 
    for(int i=0;i<n/2;i++){
        for(int j=0;j<n/2;j++){
            *(A11+i*2+j)=a[i][j];
        }
    }
    for(int i=0;i<n/2;i++){
        for(int j=0;j<n/2;j++){
            *(A12+i*2+j)=a[i][j+2];
        }
    }
    for(int i=0;i<n/2;i++){
        for(int j=0;j<n/2;j++){
            *(A21+i*2+j)=a[i+2][j];
        }
    }
    for(int i=0;i<n/2;i++){
        for(int j=0;j<n/2;j++){
            *(A22+i*2+j)=a[i+2][j+2];
        }
    }
    for(int i=0;i<n/2;i++){
        for(int j=0;j<n/2;j++){
            *(B11+i*2+j)=b[i][j];
        }
    }
    for(int i=0;i<n/2;i++){
        for(int j=0;j<n/2;j++){
            *(B12+i*2+j)=b[i][j+2];
        }
    }
    for(int i=0;i<n/2;i++){
        for(int j=0;j<n/2;j++){
            *(B21+i*2+j)=b[i+2][j];
        }
    }
    for(int i=0;i<n/2;i++){
        for(int j=0;j<n/2;j++){
            *(B22+i*2+j)=b[i+2][j+2];
        }
    }
    
    // strassen's algorithm 
    int *p,*q,*r,*s,*t,*u,*v;
    p=mul(add(A11,A22,2),add(B11,B22,2),n/2);
    q=mul(add(A21,A22,2),B11,n/2);
    r=mul(A11,sub(B12,B22,2),n/2);
    s=mul(A22,sub(B21,B11,2),n/2);
    t=mul(add(A11,A12,2),B22,n/2);
    u=mul(sub(A21,A11,2),add(B11,B12,2),n/2);
    v=mul(sub(A12,A22,2),add(B21,B22,2),n/2);
    int *c11=new int[2*2],*c12=new int[2*2],*c21=new int[2*2],*c22=new int[2*2];
    c11=add(sub(p,t,2),add(s,v,2),2);
    c12=add(r,t,2);
    c21=add(q,s,2);
    c22=add(sub(p,q,2),add(r,u,2),2);
    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
            c[i][j]=*(c11+i*2+j);
        }
    }
    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
            c[i][j+2]=*(c12+i*2+j);
        }
    }
    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
            c[i+2][j]=*(c21+i*2+j);
        }
    }
    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
            c[i+2][j+2]=*(c22+i*2+j);
        }
    }

    // displaying resultant matrix
    cout<<"matric AXB is \n";
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            cout<<c[i][j]<<" ";
        }
        cout<<endl;
    }
    
    return 0;
}   