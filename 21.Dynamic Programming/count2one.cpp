#include<iostream>
using namespace std;
int countStepsTo1(int n){
    int *arr = new int[n+1];
    for(int i = 0;i<=n;i++)
        arr[i] = 0;
    arr[1] = 0;
    arr[2] = 1;
    arr[3] = 1;
    int a ,b , c;
    for(int i = 4;i<=n;i++)
    {
        a = b = c = INT_MAX;
        a = arr[i-1];
        if(i % 2 == 0)
            b = arr[i/2];
        if(i%3 == 0)
            c = arr[i/3];

        arr[i] = 1+ min(a,min(b,c));
    }

    int res = arr[n];
    delete []arr;
    return res;
}
/*
int helper(int n, int *arr)
{
    if(n == 1)
    {
        return 0;
    }

    if(arr[n] != -1)
    {
        return arr[n];
    }
    int a = a = helper(n-1,arr);
    int b = INT_MAX,c = INT_MAX;
    if(n%2 == 0)
    {
        b = helper(n/2,arr);
    }
    if(n%3 == 0)
    {
        c = helper(n/3,arr);
    }
    arr[n]= 1+min(a,min(b,c));
    return 1+min(a,min(b,c));

}

//MEMOISATION
int countStepsTo1(int n){
    int *arr = new int[n+1];
    for(int i = 0;i<=n;i++)
    {
        arr[i] = -1;
    }
    return helper(n,arr);
}

*/
//BRUTE FORCE
/*
int countStepsTo1(int n){
    if(n == 1)
    {
        return 0;
    }
    int a = INT_MAX,b = INT_MAX,c = INT_MAX;
    if(n%2 == 0)
    {
        b = countStepsTo1(n/2);
    }
    if(n%3 == 0)
    {
        c = countStepsTo1(n/3);
    }
    else
    {
         a = countStepsTo1(n-1);
    }
    return 1+min(a,min(b,c));
}
*/
int main(){

  int n;
  cin  >> n;
  cout << countStepsTo1(n) << endl;

}
