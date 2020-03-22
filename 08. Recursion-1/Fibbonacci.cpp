#include<iostream>
using namespace std;
int fibbo(int n)
{
    if(n == 0)
    {
        return 0;
    }
    if(n == 1)
    {
        return 1;
    }
    return fibbo(n-1) + fibbo(n-2);
}
int main()
{
    int n;
    cin>>n;
    cout<<"The number on "<<n<<"th Fibbonacci is : "<<fibbo(n);
    return 0;
}

