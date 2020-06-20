#include<iostream>
using namespace std;
int fibbo3(int n)
{
    int *arr = new int[n+1];
    arr[0] = 0;
    arr[1] = 1;

    for(int i = 2;i<=n;i++)
    {
        arr[i] = arr[i-1]+arr[i-2];
    }
    return arr[n];
}

int helper(int n,int *arr)
{
    if(n<=1)
    {
        return n;
    }

    if(arr[n]!=-1)
    {
        return arr[n];
    }

    int a = helper(n-1,arr);
    int b = helper(n-2,arr);

    arr[n] = a+b;

    return a+b;
}
int fibbo2(int n)
{
    int *arr = new int[n+1];
    for(int i = 0;i<=n;i++)
    {
        arr[i] = -1;        //For innitialization
    }
    return helper(n,arr);
}
int fibbo(int n) //Brute force Approach
{
    if(n<=1)
    {
        return n;
    }
    return fibbo(n-1)+fibbo(n-2);
}
int main()
{
    int n;
    cin>>n;
    cout<<"Fibonacci no. for "<<n<<" is "<<fibbo3(n);
}
