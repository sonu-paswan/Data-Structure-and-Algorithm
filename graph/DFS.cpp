#include <iostream>
#include <list>
using namespace std;
void addEdge(list <int> v[],int a,int b){
    v[a].push_back(b);
    v[b].push_back(a);
}
list <int> visited[5];
void DFS(list <int> vtx[],int v){
    
}
int main()
{   int count = 5;
    list<int> v[count];
    addEdge(v,0,1);
    addEdge(v,1,2);
    addEdge(v,1,3);
    addEdge(v,2,3);
    addEdge(v,3,4);
    return 0;
}