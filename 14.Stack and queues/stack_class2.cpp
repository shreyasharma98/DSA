#include<iostream>
using namespace std;
//dynamic
class stackUsingDArray{
    int *data;
    int nxtIdx;
    int capacity;
public :
    stackUsingDArray()
    {
        data = new int[4];
        nxtIdx  = 0;
        capacity =  4;
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
            int *new_arr = new int[2*capacity];
            for(int i = 0;i<capacity;i++)
            {
                new_arr[i]=data[i];
            }
            capacity = 2*capacity;
            delete []data;
            data = new_arr;
        }
        data[nxtIdx] = x;
        nxtIdx++;
    }
    int top()
    {
        return data[nxtIdx];
    }
};

