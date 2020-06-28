#include <iostream>
#include <vector>
#include <climits>
using namespace std;
int helper(int **input,int m, int n , int i , int j)
{
    if(i == m || j == n)
    {
        return INT_MAX;
    }
    if(i == m-1 && j == n-1)
    {
        return input[i][j];
    }

    int a = helper(input,m,n,i+1,j+1);
    int b = helper(input,m,n,i,j+1);
    int c = helper(input,m,n,i+1,j);

    return input[i][j] + min(a,min(b,c));
}
int minCostPath(int **input, int m, int n) {
   return helper(input,m,n,0,0);
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

