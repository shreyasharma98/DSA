#include<iostream>
using namespace std;

int Find_first_index(int arr[],int n,int x)
{
    if(n==0)
    {
        return -1;
    }
    if(arr[0] == x)
    {
        return 0;
    }
    int ans = Find_first_index(arr+1,n-1,x);
    if(ans == -1)
    {
        return -1;
    }
    return ans+1;

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
    cout<<"Found the first occurance of "<<x<<" at index "<<Find_first_index(p,n,x);

    delete [] p;
    return 0;
}

