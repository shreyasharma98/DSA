#include<iostream>
using namespace std;

int main()
{
    string s1 = "abc";
    for(int i = 0;i<3;i++)
    {
        for(int j = i;j<s1.size();j++)
        {
            for(int k = i;k<=j;k++)
            {
                cout<<s1[k]<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}
