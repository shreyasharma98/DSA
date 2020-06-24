#include "ourMap.h"
#include<iostream>
#include<string>
using namespace std;

int main()
{
    myMap<int> map1;
    for(int i =0;i<10;i++)
    {
        char ch = '0'+i;
        string key = "abc";
        key += ch;
        int val  = i+1;
        map1.insert(key,val);
        cout<<map1.get_Load()<<endl;
    }
    for(int i =0;i<10;i++)
    {
        char ch = '0'+i;
        string key = "abc";
        key += ch;
        cout<<"key "<<key<<" : " << map1.search(key)<<endl;
    }

    cout<<map1.getSize()<<endl;
    return 0;
}
