#include<iostream>
using namespace std;

bool sorted(int arr[],int n)
{
    if(n == 0 || n==1)
    {
        return true;
    }
    if(arr[0]>arr[1])
    {
        return false;
    }
    return sorted(arr+1,n-1);
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
    int is_Sorted = sorted(p,n);
    if(is_Sorted){cout<<"True \n";}
    else{cout<<"False \n";}
    delete [] p;
    return 0;
}
