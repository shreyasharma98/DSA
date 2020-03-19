#include<iostream>
using namespace std;

bool sorted(int arr[],int n,int x)
{
   if(arr[0] == x)
   {
       return true;
   }
   if(n == 1 && arr[0] != x)
   {
       return false;
   }
   return sorted(arr+1,n-1,x);
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
    int is_Sorted = sorted(p,n,x);
    if(is_Sorted){cout<<"True \n";}
    else{cout<<"False \n";}
    delete [] p;
    return 0;
}

