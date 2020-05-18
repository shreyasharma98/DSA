#include<iostream>
#include "Que_class.cpp"
using namespace std;

int main()
{
    Queue<int> q1(4);
    q1.enque(10);
    q1.enque(20);
    q1.enque(30);
    q1.enque(40);
    q1.enque(50);


    cout<<endl<<q1.deque();
    cout<<endl<<q1.deque();
    cout<<endl<<q1.front();
    cout<<endl<<q1.getSize();
    q1.enque(50);
    cout<<endl<<q1.getSize();
}
