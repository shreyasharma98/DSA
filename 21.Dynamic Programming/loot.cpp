#include <iostream>
#include <vector>
#include <climits>
using namespace std;
/*
int getMaxMoney(int arr[], int n){
    if(n == 0)
    {
        return 0;
    }
    if(n == 1)
    {
        return arr[0];
    }
    if(n == 2)
    {
        return max(arr[0],arr[1]);
    }
    int a = getMaxMoney(arr+1,n-1);
    int b = arr[0] + getMaxMoney(arr+2,n-2);

    return max(a,b);
}*/
int helper(int arr[],int n,int *p)
{
     if(n == 0)
    {
        return 0;
    }
    if(n == 1)
    {
        return arr[0];
    }
    if(n == 2)
    {
        return max(arr[0],arr[1]);
    }
    int ans;
    if(p[n-1]!=-1)
    {
        ans =  p[n-1];
    }
    else{

        int a = helper(arr+1,n-1,p);
        int b = arr[0] + helper(arr+2,n-2,p);
        ans = max(a,b);
    }
    p[n-1] = ans;

    return ans;
}
int getMaxMoney(int arr[], int n){
    int *p = new int[n];
    for(int i =0;i<n;i++)
    {
        p[i]= -1;
    }
    return helper(arr,n,p);
}

int main(){
    int n;
    cin >> n;
    int arr[10000];
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    cout << getMaxMoney(arr, n);
}
