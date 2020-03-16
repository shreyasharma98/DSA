
#include<iostream>
using namespace std;

int main() {
    int n;
    cin>>n;
    char c = 'A';
    int i=1;
    while(i<=n)
    {
        int j=1;
        while(j<=i)
        {
            cout<<c;
            j++;
        }
        cout<<"\n";
        i++;c++;
    }
    return 0;}




