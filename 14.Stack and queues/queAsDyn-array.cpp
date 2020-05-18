#include<iostream>
#include "DynamicQue.cpp"
using namespace std;

int main()
{
    Queue<int> q1;
    q1.enque(10);
    q1.enque(20);
    q1.enque(30);
    q1.enque(40);
    q1.enque(50);


    cout<<endl<<q1.deque();
    cout<<endl<<q1.deque();
    cout<<endl<<q1.front();
    cout<<endl<<q1.getSize();
    q1.enque(60);
    q1.enque(80);
    q1.enque(70);
    cout<<endl<<q1.getSize();
}

