
#include<iostream>
using namespace std;

int lastIndex(int input[], int n, int x) {
if(input[n-1]==x)
{
    return n-1;
}
if(n==0)
{
    return -1;
}
return lastIndex(input,n-1,x);
}

int main()
{
    int n;
    cin>>n;

    int *p = new int[n];
    for(int i = 0;i<n;i++)
    {
        cin>>p[i];
    }
    int x;
    cin>>x;
    cout<<"Found the last occurance at "<<lastIndex(p,n,x);

    delete [] p;
    return 0;
}

