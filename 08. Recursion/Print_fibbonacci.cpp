#include<iostream>
using namespace std;
int fibbo(int n)
{
if(n == 0){cout<<0<<" ";return 0;}
else if(n == 1){cout<<1<<" ";return 1;}

else {  int val = (fibbo(n-2)+fibbo(n-1));
        cout<<val<<" ";
}
}

int main()
{
    int n;
    cin>>n;
    fibbo(n);
    return 0;
}

