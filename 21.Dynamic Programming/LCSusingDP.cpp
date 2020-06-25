
#include<iostream>
#include<string>
using namespace std;
int LCS(string s1,string s2)
{
    int ans;
    int m = s1.size();
    int n = s2.size();
    int **arr = new int*[m+1];
    for(int i=0;i<=m;i++)
    {
       arr[i] = new int[n+1];
    }
    arr[0][0] = 0;
    for(int i = 0;i<=n;i++)
    {
        arr[0][i] = 0;
    }
    for(int i = 0;i<=m;i++)
    {
        arr[i][0] = 0;
    }
    for(int i = 1; i <= m; i++) {
        for(int j = 1; j <= n; j++) {
            if(s1[m-i] == s2[n-j])
            {
               arr[i][j] = 1+ arr[i-1][j-1];
            }
            else{
            int a = arr[i-1][j-1];
            int b = arr[i][j-1];
            int c = arr[i-1][j];
            arr[i][j] = max(a,max(b,c));
            }
        }
    }

    return arr[m][n];
}
int main()
{
    string s1,s2;
    cin>>s1>>s2;
    cout<<LCS(s1,s2)<<endl;

}
