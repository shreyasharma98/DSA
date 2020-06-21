#include<iostream>
#include<cmath>
using namespace std;

int minCountDP(int n){
    if(n <= 3)
    {
        return n;
    }
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 3;
    for(int i=4;i<=n;i++)
    {
        int ans = i;
        for(int j = 1;j<=i/2;j++)
        {
            int k = i - (j*j);
            if(k>=0)
                ans = min(ans,dp[k]+1);
        }
        dp[i] = ans;
    }

    int res = dp[n];

    delete[] dp;

    return res;

}

int minCountRecur(int n){
    if(sqrt(n) == floor(sqrt(n)))   //if a number is a perfect square
    {
        return 1;	            // return 1 (9 = 3^2)
    }
    if(n <= 3)
    {
        return n;
    }
    int a = n;        // The basic illustration would be 1^2+1^2+1^2..

    for(int i = 1;i<=n;i++)   // Find the squares <= n
    {
        int x = i*i;
        if(x>n)
        {
            break;      // x has become greater than n.
        }
        else
        {
            a = min(a, 1+ minCount(n-x));  // find the min among all the representation
        }
    }

    return a;
}

int helper(int n, int *arr)
{
     if(sqrt(n) == floor(sqrt(n)))   //if a number is a perfect square
    {
        return 1;	            // return 1 (9 = 3^2)
    }
    if(n <= 3)
    {
        return n;
    }
    int ans;
    if(arr[n]!=-1)
    {
        ans = arr[n];
    }
    else
    {
        ans = n;
        for(int i = 1;i<=n;i++)   // Find the squares <= n
        {
            int x = i*i;
            if(x>n)
            {
                break;      // x has become greater than n.
            }
            else
            {
                ans = min(ans, 1+ helper(n-x,arr));  // find the min among all the representation
            }
        }
        arr[n] = ans;
    }

    return ans;
}
int minCountMemo(int n){
    int *arr = new int[n+1];
    for(int i =0;i<=n;i++)
    {
        arr[i] = -1;
    }

    return helper(n,arr);
}
int main(){

    int num;
    cin >> num;
    cout << minCountRecur(num)<<endl;
    cout << minCountMemo(num)<<endl;
    cout << minCountDP(num)<<endl;
}

