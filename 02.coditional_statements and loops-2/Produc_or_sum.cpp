#include<iostream>
using namespace std;

int main()
{
    int n,ch;
    cin>>n>>ch;
    if(ch==1)
    {
        int sum=0;
        for(int i=1;i<=n;i++)
        {
            sum+=i;
        }
        cout<<sum;
    }else if(ch==2)
    {
        int product =1;
        for(int i=1;i<=n;i++)
        {
            product*=i;
        }
        cout<<product;
    }
    else{cout<<-1;}
    return 0;
}
