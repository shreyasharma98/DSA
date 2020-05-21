#include<iostream>
using namespace std;
//static
class stackUsingArray{
    int *data;
    int capacity;
    int nxtIdx;
public :
    stackUsingArray(int total_size)
    {
        data = new int[total_size];
        nxtIdx  = 0;
        capacity =  total_size;
    }
    int size()
    {
        return nxtIdx;
    }
    bool isEmpty()
    {
        /*if(nxtIdx == 0)
        {
            return true;
        }
        return false;*/
        return nxtIdx == 0;
    }
    int pop()
    {
        nxtIdx--;
        return data[nxtIdx];
    }
    void Push(int x)
    {
        if(nxtIdx == capacity)
        {
            cout<<"Stack Full!";
            return;
        }
        data[nxtIdx] = x;
        nxtIdx++;
    }
    int top()
    {
        return data[nxtIdx];
    }
};
