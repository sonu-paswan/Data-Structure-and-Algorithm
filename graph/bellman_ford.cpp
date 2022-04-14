#include <bits/stdc++.h>
using namespace std;
#define Max 99999
int main()
{
    int n, e, source, s, d, w;
    cout << "enter the number of vertex in a graph :";
    cin >> n;
    int cost[n][n], dist[n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cost[i][j] = Max;
        }
    }
    cout << "enter the number of edges in a graph :";
    cin >> e;
    cout << "enter your source vertex in number: ";
    cin >> source;
    for (int i = 0; i < e; i++)
    {
        cout << "edge" << i + 1 << " source "
             << " destination "
             << " weight ";
        cin >> s >> d >> w;
        cost[s][d] = w;
    }
    // bellman ford algorithm
    for (int i = 0; i < n; i++)
    {
        dist[i] = Max;
    }
    dist[source] = 0;
    for (int k = 1; k < n; k++) // for n-1 passes 
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if ((cost[i][j] != Max) && (dist[j] > cost[i][j] + dist[i])) // relaxation
                {
                    dist[j] = cost[i][j] + dist[i];
                }
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << dist[i] << " ";
    }
}

// class test case
// enter the number of vertex in a graph :5
// enter the number of edges in a graph :10
// enter your source vertex in number: 0
// edge1 source  destination  weight 0 1 6
// edge2 source  destination  weight 0 2 7
// edge3 source  destination  weight 1 2 8
// edge4 source  destination  weight 1 4 -4
// edge5 source  destination  weight 1 3 5
// edge6 source  destination  weight 3 1 -2
// edge7 source  destination  weight 2 3 -3
// edge8 source  destination  weight 2 4 9
// edge9 source  destination  weight 4 0 2
// edge10 source  destination  weight 4 3 7

// 0 2 7 4 -2