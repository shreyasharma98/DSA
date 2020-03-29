#include<iostream>
#include<cstring>
using namespace std;
bool func(char large[],char ch[])
{
    if(ch[0]=='\0')
    {
        return true;
    }
    if(large[0] == '\0')
    {
        return false;
    }
    if(ch[0] == large[0])
    {
        return func(large,ch+1);
    }
    else
    {
      return func(large+1,ch);
    }

}

int main()
{
    char ch1[100],ch2[100];
    cin>>ch1;
    cin>>ch2;
    bool x = func(ch1,ch2);
    if(x){cout<<"true";}
    else{cout<<"false";}
    return 0;
}
