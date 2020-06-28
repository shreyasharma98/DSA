#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int minCostPath(int **input, int m, int n) {
   int **arr = new int*[m];
    for(int i = 0; i < n; i++) {
        arr[i] = new int[n];
    }
    //Fill last
    arr[m-1][n-1]= input[m-1][n-1];
    for(int i = n-2;i>=0;i--)
    {
        arr[m-1][i]= arr[m-1][i+1]+input[m-1][i];
    }
    for(int i = m-2;i>=0;i--)
    {
        arr[i][n-1] = input[i][n-1]+arr[i+1][n-1];
    }

    for(int i = m-2;i>=0;i--)
    {
        for(int j = n-2;j>=0;j--)
        {
            arr[i][j] = min(arr[i][j+1],min(arr[i+1][j],arr[i+1][j+1]))+input[i][j];
        }
    }

    return arr[0][0];
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


