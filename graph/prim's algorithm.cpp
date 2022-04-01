#include <iostream>
#include <limits.h>
using namespace std;
int * Min(int *p,int n){
    int *arr=new int [3];
     arr[2]=INT_MAX;
    for(int i=1;i<n;i++){
        for(int j=i;j<n;j++){
            if(*(p+i*n +j)<arr[2]&&i!=j){
            arr[2]=*(p+i*n+j);
            arr[0]=i;
            arr[1]=j;
            
            }
        }
    }
    return arr;
}
int prim(int *cost,int n,int *t){
    int *mini=Min(cost,n);
    int k=*(mini);
    int l=*(mini+1);
    *(t+0)=k;
    *(t+0*2 +1)=l;
    int mincost=*(mini+2);
    int *next=new int[n];
    for(int i=1;i<n;i++){
        if(*(cost+i*n+k)<*(cost + i*n +l))
        next[i]=k;
        else
        next[i]=l;
    }
    next[k]=0;next[l]=0;
    for(int i=2;i<n-1;i++){
        int mina=INT_MAX,indj;
        for(int j=1;j<n;j++){
            if(next[j]!=0&&*(cost+j*n + next[j])!=0&&(*(cost+j*n + next[j])<mina)){
                mina=*(cost+j*n + next[j]);
                indj=j;
            }
        }
        *(t +(i-1)*2)=indj;
        *(t +(i-1)*2 +1)=next[indj];
        mincost+=*(cost+indj*n+next[indj]);
        next[indj]=0;
        for(k=1;k<n;k++){
            if(next[k]!=0&&*(cost+k*n+next[k])>*(cost+k*n+indj)){
                next[k]=indj;
            }
        } 
    }
    return mincost;
}
int main()
{   cout<<"enter the number of vertices :";
    int m,w;
    cin>>m;
    int n=m+1;
    int cost[n][n];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++){
            if(i==j||i==0||j==0){
                cost[i][j]=0;
                continue;
            }
            cout<<"weight "<<i<<" "<<j<<" :";
            cin>>w;
            if(w==-1){
            cost[i][j]=INT_MAX;
            }
            else{
                cost[i][j]=w;
            }
        }
    }
    
    int t[n-2][2];
    int ans=prim((int *)cost,n,(int *)t);
    for(int i=0;i<n-2;i++){
        cout<<"edge "<<i+1<<" ("<<t[i][0]<<","<<t[i][1]<<") cost :"<<cost[t[i][0]][t[i][1]]<<endl;
    }
    cout<<"\nanswer :"<<ans;
    return 0;
}
// creating adjacency matrix of graph
    // cost[1][2]=28;
    // cost[2][1]=28;

    // cost[1][6]=10;
    // cost[6][1]=10;

    // cost[2][3]=16;
    // cost[3][2]=16;

    // cost[2][7]=14;
    // cost[7][2]=14;

    // cost[3][4]=12;
    // cost[4][3]=12;

    // cost[4][5]=22;
    // cost[5][4]=22;

    // cost[4][7]=18;
    // cost[7][4]=18;

    // cost[5][6]=25;
    // cost[6][5]=25;

    // cost[5][7]=24;
    // cost[7][5]=24;
    // output -> 99

    // example 2
    // cost[1][2]=10;
    // cost[2][1]=10;

    // cost[2][5]=6;
    // cost[5][2]=6;

    // cost[1][4]=4;
    // cost[4][1]=4;

    // cost[1][3]=5;
    // cost[3][1]=5;

    // cost[3][5]=9;
    // cost[5][3]=9;

    // cost[3][4]=8;
    // cost[4][3]=8;

    // cost[5][6]=4;
    // cost[6][5]=4;

    // cost[4][6]=7;
    // cost[6][4]=7;
    // output -> 26
