

#include<iostream>
using namespace std;
void Arrange(int *arr,int n)
{
    int val=1;
    for(int i=0;i<=(n-1)/2;i++)
    {
        arr[i]=val;
        val+=2;
    }
    if(n%2 == 0 ){val = n;}
    else {val = n-1;}
    for(int i=(n+1)/2;i<n;i++)
    {
        arr[i]=val;
        val-=2;
    }
}
int main()
{
    int n,x;
    cin>>n;
    int *p = new int[n];
    Arrange(p,n);
    for(int i=0;i<n;i++)
    {
        cout<<p[i]<<" ";
    }
    delete p;
    return 0;
}
