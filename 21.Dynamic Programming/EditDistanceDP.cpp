#include <iostream>
#include <string>
using namespace std;

int editDistance(string s1, string s2){

    int m = s1.size();
    int n = s2.size();
    int **arr = new int*[m+1];
    for(int i=0;i<=m;i++)
    {
       arr[i] = new int[n+1];
    }
    arr[0][0] = 0;
    for(int i = 1;i<=m;i++)
    {
        arr[i][0] = i;
    }

    for(int i = 1;i<=n;i++)
    {
        arr[0][i] = i;
    }

    for(int i = 1;i<=m;i++)
    {
        for(int j = 1;j<=n;j++)
        {
            if(s1[m-i] == s2[n-j])
            {
                arr[i][j] = arr[i-1][j-1];
            }
            else
                arr[i][j] = min(arr[i-1][j-1],min(arr[i][j-1],arr[i-1][j])) +1;
        }
    }


    return arr[m][n];

}
int main(){

  string s1;
  string s2;

  cin >> s1;
  cin >> s2;

  cout << editDistance(s1,s2) << endl;

}
