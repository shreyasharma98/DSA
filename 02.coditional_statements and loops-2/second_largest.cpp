#include<iostream>
using namespace std;
int main()
{
    int n,next,f_large = INT_MIN,s_large=INT_MIN;
    cin>>n;
    cin>>f_large;
    for(int i =2;i<=n;i++)
    {
        cin>>next;
        if(next > f_large)
        {
            s_large = f_large;
            f_large = next;
        }
        else if(next<f_large && next >s_large )
        {
            s_large = next;
        }
    }
    cout<<s_large;
    return 0;
}
