#include<iostream>
#include<vector>
using namespace std;

int main()
{
    vector<int> v1;      //Vector is a template class therefore we've to always mention the type of data we've to put for ex: <int>,<double> etc
    v1.push_back(10);   //insert in a vector using push_back()
    v1.push_back(20);
    v1.push_back(30);
    v1[2] = 40;            //to update/modify element at any idx we hve to use [] same as that in array
    //cout<<v1[0]<<endl<<v1[1]<<endl<<v1[2]<<endl;   //access any idx of vector using [] like in array

    cout<<endl;
    // BUT Can we also put the values using [] in a vector??????? Let's see
    v1[3] = 60;     // [] is not used to put values in a vector
    v1[4] = 70;     // ''
    v1.push_back(290);
    v1.push_back(310);
    //cout<<v1[0]<<endl<<v1[1]<<endl<<v1[2]<<endl<<v1[3]<<endl<<v1[4]<<endl<<v1[5]<<endl<<v1[6]<<endl;
    for(int i = 0;i<v1.size();i++)
    {
        cout<<v1[i]<<" ";         //only show 290 and 310 not 60 and 70.
    }

        cout<<endl;
    //cout<<v1.size()<<"  "<<v1.capacity();

    //In vector to dynamically store value it initially creates a vector of size 0..as the element kept on pushing it increase it size as per requirement.

    vector<int>  v2;

    for(int i = 0;i<50;i++)
    {
        cout<<"size : "<<v2.size()<<"   capacity : "<<v2.capacity()<<endl;
        v2.push_back(i+2);
    }
    //pop_back() removes the top_most elemnt of the vector
    vector<int>  v3;
    v3.push_back(10);
    v3.push_back(20);
    v3.push_back(30);
    //10 20 30
    v3.pop_back();//10 20
    v3.pop_back();//10
    
    
    return 0;
}
