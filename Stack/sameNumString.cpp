// code for checking equal number of characters in a string 
#include <iostream>
#include <string>
#include <stack>
#include <cstring>
using namespace std;

int main()
{   
    // char a[]="ababb";
    string a;
    cout<<"enter string \n";
    cin>>a;
    stack <char > s;
    // s.push(a[0]);
    int i=0;
    // char *p=a;
    while(a[i]!='\0'){
        // p++;
        if(s.empty()){
            s.push(a[i]);
        }
        else if(a[i]==s.top()){
            s.push(a[i]);

        }
        else{
            s.pop();
        }
        i++;
    }
    if(s.empty()){
        cout<<"true";
    }
    else
    cout<<"false ";
    return 0;
}