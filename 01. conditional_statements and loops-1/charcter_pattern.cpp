
#include<iostream>
using namespace std;


int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        for(int j = i ; j<=2*i;j++)
        {
            cout<<char(65+j);
        }
        cout<<endl;
    }


}

