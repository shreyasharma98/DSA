
#include<iostream>
using namespace std;
int linear_search(int *p,int n, int x)
{
    for(int i=0;i<n;i++)
    {
        if(p[i] == x)
        {
         return i;
        }
    }
    return -1;
}
int main()
{
    int n,x;
    cin>>n;
    int *p = new int[n];
    for(int i=0;i<n;i++)
    {
        cin>>p[i];
    }
    cin>>x;
    cout<<"\n"<<linear_search(p,n,x);

    return 0;
}
