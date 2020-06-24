#include<iostream>
#include<unordered_map>
#include<string>
using namespace std;

int main()
{
    unordered_map<string,int> ourMap;
    ourMap["abc"] = 1;
    ourMap["abc2"] = 2;
    ourMap["abc3"] = 3;
    ourMap["abc4"] = 4;
    ourMap["abc5"] = 5;
    ourMap["abc6"] = 6;

    unordered_map<string,int> :: iterator it = ourMap.begin();
    while(it!=ourMap.end())
    {
        cout<< "Key : "<<it->first;
        cout<<" value : "<<it->second<<endl;
        it++;
    }
    unordered_map<string,int> :: iterator it2 = ourMap.find("abc");  //it will point to abc.
    cout<<"The size of map : "<< ourMap.size() <<endl;

    ourMap.erase(it2,it2 + 3);

    cout<<"The size of map : "<< ourMap.size() <<endl;


}
