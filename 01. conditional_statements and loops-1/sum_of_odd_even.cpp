#include<iostream>
using namespace std;

int main() {

    int n;
    cin>>n;
    int even=0,odd=0,rem;
    while(n!=0)
    {
        rem = n%10;
        if(rem %2 == 0){even+=rem;}
        else {odd+=rem;}
        n=n/10;
    }
    cout<<even<<" "<<odd;
return 0;
}

