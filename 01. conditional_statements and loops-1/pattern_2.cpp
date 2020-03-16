
#include<iostream>
using namespace std;

int main()
{
    int n;
    cin>>n;

    int i=1;
    while(i<=n)
    {
        int k =1;
        while(k<=n-i)
        {
            cout<<" " ;
            k++;
        }
        int j = i;
        while(j<2*i)
        {
            cout<<j;
            j++;
        }
        cout<<"\n";
        i++;
    }
    return 0;
}

