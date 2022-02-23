// graph representation using adjacency list
// using vectors(STL sequence containers)

#include <bits/stdc++.h>
using namespace std;
void addLink(vector <int> vec[],int a,int b){
    vec[a].push_back(b);
    vec[b].push_back(a);
}
void printGraph(vector <int> v[],int size){
    for(int i=0;i<size;i++){
        cout<<i<<"->";
        for(auto x:v[i]){
            cout<<x<<" ";
        }
        cout<<endl;
    }
}
int main()
{   
    int count=5;
    vector <int> v[count]; // array of empty vectors 
    addLink(v,0,1);
    addLink(v,1,2);
    addLink(v,1,3);
    addLink(v,2,3);
    addLink(v,3,4);
    printGraph(v,count);
    return 0;
}