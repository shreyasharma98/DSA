#include<iostream>
#include<cmath>
using namespace std;

int main()
{
    int n,i=0,ans=0,rem;
    cin>>n;
    while(n)
    {
        rem = n%10;
        ans += rem*pow(2,i);
        n=n/10;
        i++;
    }
    cout<<ans;
    return 0;
}
