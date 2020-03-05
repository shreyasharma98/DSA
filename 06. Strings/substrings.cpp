#include<iostream>
#include<cstring>
using namespace std;
void print_substrings(char str[])
{
    int n = strlen(str);
    for(int i = n-1;i>=0;i--)
    {
        for(int j = i;j<n;j++)
        {
            for(int k = i;k<=j;k++)
            {
                cout<<str[k];
            }
        cout<<"\n";
        }
    }
}
int main()
{
    char str[10000];
    cin.getline(str,10000);

    print_substrings(str);
    return 0;
}
