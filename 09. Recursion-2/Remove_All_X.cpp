#include<iostream>
using namespace std;

void remove_x(char ch[])
{
    if(ch[0] == '\0')
    {
        return;
    }
    if(ch[0] != 'x')
    {
        remove_x(ch+1);
    }
    else
    {
        int i=0;
        for(;ch[i]!='\0';i++)
        {
        ch[i] = ch[i+1];
        }
        ch[i]=ch[i+1];
        remove_x(ch);
    }
}
int main()
{
    char ch[100];
    cin.getline(ch,100);
    remove_x(ch);
    cout<<ch;
    return 0;
}
