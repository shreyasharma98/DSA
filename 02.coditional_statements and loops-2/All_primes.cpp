#include<iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    for(int i=2;i<=n;i++)
    {
        bool isPrime = true;
        for(int j = 2;j<=n;j++)
        {
            if(i!=j)
            {
                if(i%j == 0)
                {
                    isPrime = false;
                    break;
                }
            }

        }
        if(isPrime){cout<<i<<"\n";}
    }
    return 0;
}
