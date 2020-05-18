#include<iostream>
using namespace std;

template <typename T,typename V>

class box
{
    T len;
    V bre;

public:
    box(T l,V b)
    {
        this->len = l;
        this->bre = b;
    }

    V area()
    {
        return len*bre;
    }
    void show()
    {
        cout<<"the length = "<<len<<endl;
        cout<<"the breadth = "<<bre<<endl;
    }
};
