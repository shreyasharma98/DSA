#include<iostream>
using namespace std;

int main() {

    int n,pre,cur;
    bool dec = true;
    cin>>n;
    cin>>pre;
    while(n-1)
    {
        cin>>cur;
        if(pre==cur)
        {
            cout<<"false";
            return 0;
        }
        else if(pre<cur)
        {
            if(dec)
            {
                dec = false;
            }
        }
        else{
            if(dec == false)
            {
                cout<<"false";
                return 0;
            }
        }
    }
    cout<<true;

}

