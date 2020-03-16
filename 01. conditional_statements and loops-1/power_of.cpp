#include<iostream>
using namespace std;

int main() {
    int x,n,res=1;
    cin>>x>>n;
    for(int i =0;i<n;i++)
    {
        res*= x;
    }
	cout<<res;
}

