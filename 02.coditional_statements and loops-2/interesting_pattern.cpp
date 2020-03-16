#include<iostream>
using namespace std;


int main(){

    int n;
    cin>>n;
    for(int i =n;i>=1;i--)
    {
        for(int j =1;j<=i;j++)
        {
            cout<<j;
        }
        for(int k = 1;k<=n-i;k++)
        {
            cout<<"*";
        }
         for(int k = 1;k<=n-i;k++)
        {
            cout<<"*";
        }
        for(int j = i;j>=1;j--)
        {
            cout<<j;
        }

        cout<<"\n";
    }
}



