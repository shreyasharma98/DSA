#include<iostream>
using namespace std;
//DP

long staircase(int n){
    long *arr = new long[n+1];
    for(int i =0;i<=n;i++)
    {
        arr[i] = 0;
    }
    arr[0] = 0;
    arr[1] = 1;
    arr[2] = 1+arr[1];
    arr[3] = 1+arr[1]+arr[2];

    for(int i = 4;i<=n;i++)
    {
        arr[i] = arr[i-1] + arr[i-2] + arr[i-3];
    }

    int res = arr[n];
    delete []arr;
    return res;
}

//MEMOIZAATION
/*
long helper(int n,long *arr)
{
    if(n == 0)
    {
        return 0;
    }
    if(n == 1)
    {
        return 1;
    }
    if(n == 2)
    {
        return 1+helper(n-1,arr);
    }
    if(n == 3)
    {
        return 1+helper(n-1,arr)+helper(n-2,arr);
    }
    if(arr[n]!=0)
    {
        return arr[n];
    }
    long one,two,three;
    one = helper(n-1,arr);
    two = helper(n-2,arr);
    three = helper(n-3,arr);

    arr[n] = one+two+three;
    return one+two+three;
}
long staircase(int n){
    long *arr = new long[n+1];
    for(int i =0;i<=n;i++)
    {
        arr[i] = 0;
    }
    return helper(n,arr);
}
*/
//Brute Force
/*
long staircase(int n){
    if(n == 0)
    {
        return 0;
    }
    if(n == 1)
    {
        return 1;
    }
    if(n == 2)
    {
        return 1+staircase(n-1);
    }
    if(n == 3)
    {
        return 1+staircase(n-1)+staircase(n-2);
    }
    return staircase(n-1)+staircase(n-2)+staircase(n-3);
}
*/
int main(){

  int n;
  cin >> n ;
  cout << staircase(n) << endl;

}

