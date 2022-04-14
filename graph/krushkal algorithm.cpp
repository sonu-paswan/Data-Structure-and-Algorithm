#include <iostream>
#include <algorithm>
using namespace std;
// krushkal's algorithm program in cpp

int find_set(int p[], int v)
{
    if (v == p[v])
    {
        return v;
    }
    return find_set(p, p[v]);
}
void union_set(int p[], int a, int b)
{
    a = find_set(p, a);
    b = find_set(p, b);
    if (a != b)
        p[b] = a;
}
#define Max 99999

struct edge
{
    int u;
    int v;
    int e; // for edge
};
bool sortEdges(edge a, edge b)
{
    return a.e < b.e; // sorting edges with respect to their weights
}
int main()
{
    int n, e;
    cout << "enter the number of vertices :";
    cin >> n;
    int parent[n];
    for (int i = 0; i < n; i++)
    {
        parent[i] = i;
    }

    int cost[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cost[i][j] = Max;
        }
    }
    cout << "enter the number of edges :";
    cin >> e;
    edge edges[e];
    int s, d, w;
    for (int i = 0; i < e; i++)
    {
        cout << "for edge->" << i + 1 << " s , d , w :";
        cin >> s >> d >> w;
        cost[s][d] = w;
        cost[d][s] = w;
        edges[i].u = s;
        edges[i].v = d;
        edges[i].e = w;
    }
    int tree[n - 1][2]; // spanning tree 

    // krushkal's algorithm
    sort(edges, edges + e, sortEdges);
    int u, v, k = 0;
    for (int i = 0; i < e; i++)
    {
        u = edges[i].u;
        v = edges[i].v;
        if (find_set(parent, u) != find_set(parent, v)) // finding cycle 
        {
            tree[k][0] = u;
            tree[k][1] = v;
            k++;
            union_set(parent, u, v);
        }
    }
    ////////////////////////
    int sum = 0;
    for (int i = 0; i < n - 1; i++)
    {
        cout << "(" << tree[i][0] << "," << tree[i][1] << ")" << endl;
        sum += cost[tree[i][0]][tree[i][1]];
    }
    cout << "minimum cost :" << sum;
    return 0;
}