#include<iostream>
using namespace std;
bool checkMember(int n){

    int a = 1,b = 1;
    int c;
    for(int i=1;i<=n;i++)
    {
        c = a+b;
        if(a == n)
        {
            return true;
        }
        a = b;
        b = c;

    }

    return false;
}

int main()
{
    cout<<checkMember(55);
}


