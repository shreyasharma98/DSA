

#include<iostream>
using namespace std;

int main() {
    int n;
    cin>>n;
    int i=n;
    while(i>=1)
    {
        int j=i;
        while(j<=n)
        {
            cout<<char(64+j);
            j++;
        }
        cout<<"\n";
        i--;
    }
    return 0;}




