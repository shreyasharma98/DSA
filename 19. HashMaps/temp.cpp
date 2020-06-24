#include<iostream>
#include<cstring>
using namespace std;
int main()
{
    char* str = new char[15];
    char* str2 = "shreya";
    for(int i=0;str2[i]!='\0';i++)
    {
        strcat(str,str2[i]);
    }
    cout<<str;

    // signal to operating system program ran fine
    return 0;
}
