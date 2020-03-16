#include<iostream>
using namespace std;

int main()
{
    int sum = 0,n;
    cin>>n;

    int i=1;
    while(i<=n)
    {
        sum+=i;
        i++;
    }
    cout<<sum;
    return 0;
}
