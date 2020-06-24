#include<iostream>
#include<unordered_map>
#include<string>
using namespace std;

int main()
{
    unordered_map<string,int> ourMap;
    // INSERTION IN HASHMAP

    pair<string,int> p("abc",1);
    ourMap.insert(p);

    ourMap["def"] = 2;

    // CHECK SIZE OF THE MAP
    cout<<"The size of map : "<< ourMap.size() <<endl;
    //ACCESING

    cout << ourMap["abc"] <<endl;
    cout << ourMap.at("abc") <<endl;
      // For unknown keys

   // cout << ourMap.at("ghi") <<endl;  //This throws an error
    cout << ourMap["ghi"] <<endl;  // this is quite a risky way to use as if the key does not present the map..it add the key and gives is occurance as 1.

   //There4 to overcome this we'll use count()


    cout<<"The size of map : "<< ourMap.size() <<endl;
   //to check presence
   if(ourMap.count("ghi")>0)
   {
       cout<<"the string is present"<<endl;
   }

   ourMap.erase("ghi");
   if(ourMap.count("ghi")>0)
   {
       cout<<"the string is present"<<endl;
   }
   cout<<"The size of map : "<< ourMap.size() <<endl;
    return 0;
}
