#include<iostream>
using namespace std;


int main(){
    int n;
    cin>>n;
    int  i =n;
    while(i>=1)
    {
        int j = i;
        while(j>=1)
        {
            cout<<i;
            j--;
        }
        cout<<"\n";
        i--;
    }
}



