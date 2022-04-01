#include <iostream>
#include <vector>
using namespace std;

struct knap{
    float p;
    float w;
};

int main()
{   cout<<"enter the number of objects :";
    int n,m;
    cin>>n;
    knap *arr=new knap[n];
    cout<<"enter maximum number capacity of knapsack :";
    cin>>m;
    for(int i=0;i<n;i++){
        cout<<"object "<<i+1<<endl;
        cout<<"profit :";
        cin>>arr[i].p;
        cout<<"weight :";
        cin>>arr[i].w;
    }
    // sorting knaps usign bubble sort 
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-1-i;j++){
            if((arr[j+1].p/arr[j+1].w)>(arr[j].p/arr[j].w)){
                knap temp=arr[j+1];
                arr[j+1]=arr[j];
                arr[j]=temp;
            }
        }
    }
    // vector <int> v;
    // vector <int>::iterator i;
    float sum=0;
    int remain;
    for(int i=0;i<n;i++){
        if(m==0)
        {
            break;
        }
        if((arr[i].w)<m){
            // v.push_back(arr[i].w);
            sum+=arr[i].p;
            m=m-arr[i].w;
        }
        else{
            // remain=arr[i].w-m;
            remain=m;
            // m=m-remain;
            m=0;
            sum+=(remain/arr[i].w)*arr[i].p;
        }
    }
    cout<<"maximum profit is :"<<sum;
    return 0;
}