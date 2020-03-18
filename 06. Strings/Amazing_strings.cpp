#include <cstdlib>
#include<string>
#include<algorithm>
#include<iostream>
using namespace std;

void answer(string s1,string s2,string s)
{
    string res = s1+s2;
    sort(res.begin(), res.end());
    sort(s.begin(),s.end());
    if(s == res){cout<<"YES";}
    else{cout<<"NO";}
}

int main()
{
   string s1,s2,s;
   cin>>s1>>s2>>s;
   answer(s1,s2,s);
   return 0;
}