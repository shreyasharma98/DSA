#include<iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int a)
    {
        this->data = a;
        this->next = NULL;
    }

};
