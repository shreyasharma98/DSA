#include <iostream>
#include <vector>
#include <climits>
using namespace std;
int helper(int **input,int m, int n , int i , int j,int **arr)
{
    if(i == m || j == n)
    {
        return INT_MAX;
    }
    if(i == m-1 && j == n-1)
    {
        return input[i][j];
    }
    if(arr[i][j] != -1)
    {
        return arr[i][j];
    }

    int a = helper(input,m,n,i+1,j+1,arr);
    int b = helper(input,m,n,i,j+1,arr);
    int c = helper(input,m,n,i+1,j,arr);
    int ans = input[i][j] + min(a,min(b,c));
    arr[i][j] = ans;
    return ans;
}
int minCostPath(int **input, int m, int n) {
    int **arr = new int*[m];
    for(int i = 0; i < n; i++) {
        arr[i] = new int[n];
    }
     for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
             arr[i][j] = -1;
        }
    }
   return helper(input,m,n,0,0,arr);
}

int main() {
    int **arr,n,m;
    cin >> n >> m;
    arr = new int*[n];
    for(int i = 0; i < n; i++) {
        arr[i] = new int[m];
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }
    cout << minCostPath(arr, n, m) << endl;
}


