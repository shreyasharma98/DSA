#include<iostream>
using namespace std;
int find_length(char ch[])
{
    if(ch[0] == '\0')
    {
        return 0;
    }
    return 1+find_length(ch+1);
}
int main()
{
    char ch[100];
    cin.getline(ch,100);
    cout<<find_length(ch);
    return 0;
}
