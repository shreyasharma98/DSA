#include<iostream>
#include<string>
using namespace std;
int helper(string s1,string s2,int **arr)
{
    int ans;
    int m = s1.size();
    int n = s2.size();
    if(s1.size() == 0 || s2.size() == 0)
    {
        return 0;
    }

    if(arr[m][n] != -1)
    {
        return arr[m][n];
    }
     if(s1[0] == s2[0])
    {
        ans = 1+helper(s1.substr(1),s2.substr(1),arr);
    }
    else
    {
        int a = helper(s1,s2.substr(1),arr);
        int b = helper(s1.substr(1),s2,arr);
        int c = helper(s1.substr(1),s2.substr(1),arr);
        ans =  max(a,max(b,c));
    }
    arr[m][n] = ans;
    //int ans = arr[n][n];
    return arr[m][n];
}
int LCS(string s1,string s2)
{
    int m = s1.size();
    int n = s2.size();
    int **arr = new int*[m+1];
    for(int i=0;i<=m;i++)
    {
       arr[i] = new int[n+1];
    }
    for(int i = 0; i <= m; i++) {
        for(int j = 0; j <= n; j++) {
            arr[i][j]=-1;
        }
    }
    return helper(s1,s2,arr);
}
int main()
{
    string s1,s2;
    cin>>s1>>s2;
    cout<<LCS(s1,s2)<<endl;

}

