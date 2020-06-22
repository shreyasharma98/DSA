#include<iostream>
#include<string>
using namespace std;
int LCS(string s1,string s2)
{
    if(s1.size() == 0 || s2.size() == 0)
    {
        return 0;
    }
    if(s1[0] == s2[0])
    {
        return 1+LCS(s1.substr(1),s2.substr(1));
    }

    int a = LCS(s1,s2.substr(1));
    int b = LCS(s1.substr(1),s2);
    //int c = LCS(s1.substr(1),s2.substr(1));

    return max(a,b);
}
int main()
{
    string s1,s2;
    cin>>s1>>s2;
    cout<<LCS(s1,s2)<<endl;

}
