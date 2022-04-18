// all pairs shortest path 

#include <iostream>
#include<algorithm>
using namespace std;
#define Inf 99999
int main()
{
    int n, e;
    cout << "enter the number of vertices :";
    cin >> n;
    int cost[n][n];
    cout << "enter number of edges :";
    cin >> e;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j)
            {
                cost[i][j] = 0;
            }
            else
            {
                cost[i][j] = Inf;
            }
        }
    }
    int s, d, w;
    cout << "enter edges\n";
    for (int i = 0; i < e; i++)
    {
        cout << "edge " << i + 1 << " source ,destination,weight :";
        cin >> s >> d >> w;
        cost[s][d] = w;
    }
    cout<<"cost matrix \n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << cost[i][j] << " ";
        }
        cout << endl;
    }
    
    // floyd warshell algorithm
    int A[n][n];
    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            A[k][i]=cost[k][i];
        }
    }
    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                A[i][j]=min(A[i][j],A[i][k]+A[k][j]);
            }
        }
    } // time complexity -> O(v^3)
    cout<<"foly matrix of all pair shortest path \n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << A[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
// first testcase
// enter the number of vertices :4
// enter number of edges :6
// enter edges 
// edge 1 source ,destination,weight :0 1 8
// edge 2 source ,destination,weight :0 3 1
// edge 3 source ,destination,weight :1 2 1
// edge 4 source ,destination,weight :2 0 4
// edge 5 source ,destination,weight :3 2 9
// edge 6 source ,destination,weight :3 1 2

// second test case 

// enter the number of vertices :4
// enter number of edges :7
// enter edges
// edge 1 source ,destination,weight :0 1 3 
// edge 2 source ,destination,weight :0 3 7
// edge 3 source ,destination,weight :1 0 8
// edge 4 source ,destination,weight :1 2 2
// edge 5 source ,destination,weight :2 0 5
// edge 6 source ,destination,weight :2 3 1
// edge 7 source ,destination,weight :3 0 2