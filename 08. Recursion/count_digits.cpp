#include<iostream>
using namespace std;
int count(int n)
{
    if(n == 0)
    {
        return 0;
    }
    return count(n/10) +1;
}
int main()
{
    int n;
    cin>>n;
    cout<<"The no. of digits in "<<n<<" is : "<<count(n);
    return 0;
}
