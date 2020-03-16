#include<iostream>
using namespace std;

int main()
{
    int n,rem,rev =0;
    cin>>n;
    while(n)
    {
        rem = n%10;
        n=n/10;
        rev = rev*10 +rem;
    }
    cout<<rev;
    return 0;
}
