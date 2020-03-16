#include<iostream>
using namespace std;


int main(){

    int m,n,arr[10][10];
    cin>>m>>n;
    for(int i = 0;i<m;i++)
    {
        for(int j = 0;j<n;j++)
        {
            cin>>arr[i][j];
        }
    }
for(int j = 0;j<n;j++)
{
    int  sum = 0;
    for(int i = 0;i<m;i++)
    {
        sum+=arr[i][j];
    }
    cout<<sum<<" ";
}
}
