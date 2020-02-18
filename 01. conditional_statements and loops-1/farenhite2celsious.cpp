#include<iostream>
using namespace std;

int main()
{
    int beg,end,jump;
    cin>>beg>>end>>jump;
    for(;beg<=end;beg+=jump)
    {
        cout<<beg<<" "<<(beg -32)*5/9<<endl;
    }
    return 0;
}
