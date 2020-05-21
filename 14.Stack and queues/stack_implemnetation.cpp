#include<iostream>
#include"stack_class.cpp"
using namespace std;

int main()
{
    stackUsingArray s1(4);
    s1.Push(10);
    s1.Push(20);
    s1.Push(30);
    s1.Push(40);
    s1.Push(50);  //stack full
    cout<<endl;
    cout<<s1.pop()<<endl;  //40
    cout<<s1.pop()<<endl;  //30
    cout<<s1.top()<<endl;  //20
    cout<<s1.pop()<<endl;  //20
    cout<<s1.isEmpty()<<endl;
    return 0;
}
