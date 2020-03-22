#include<iostream>
using namespace std;

bool check_presence(int arr[],int n,int x)
{
   if(arr[0] == x)
   {
       return true;
   }
   if(n == 1 && arr[0] != x)
   {
       return false;
   }
   return check_presence(arr+1,n-1,x);
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
    int is_Present = check_presence(p,n,x);
    if(is_Present){cout<<"True \n";}
    else{cout<<"False \n";}
    delete [] p;
    return 0;
}

