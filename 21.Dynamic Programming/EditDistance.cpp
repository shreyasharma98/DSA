#include <iostream>
#include <string>
using namespace std;

int editDistance(string s1, string s2){
if(s1.size() == 0 && s2.size() == 0)
{
   return 0;
}
if(s1.size() == 0 || s2.size() == 0)
{
    return max(s1.size(),s2.size());
}
if(s1[0] == s2[0])
{
    return editDistance(s1.substr(1),s2.substr(1));
    //return 0;
}
    int a = 1+editDistance(s1.substr(1),s2);
    int b = 1+editDistance(s1,s2.substr(1));
    int c = 1+editDistance(s1.substr(1),s2.substr(1));

    return min(a,min(b,c));
}
int main(){

  string s1;
  string s2;

  cin >> s1;
  cin >> s2;

  cout << editDistance(s1,s2) << endl;

}
