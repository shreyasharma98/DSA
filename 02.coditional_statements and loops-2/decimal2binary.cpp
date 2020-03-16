#include<iostream>
#include<cmath>
using namespace std;

int main()
{
    long int n,pv=1,ans=0,rem;
    cin>>n;
    while(n)
    {
        rem = n%2;
        ans += rem*pv;
        n=n/2;
        pv*=10;
    }
    cout<<ans;
    return 0;
}

