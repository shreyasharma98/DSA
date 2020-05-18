#include<iostream>
using namespace std;

template <typename T, typename V>

class Pair
{
    T x;
    V y;

public:
   setX(T x)
   {
       this->x = x;
   }
   T getX()
   {
       return x;
   }
   setY(V y)
   {
       this->y = y;
   }
   V getY()
   {
       return y;
   }
};
