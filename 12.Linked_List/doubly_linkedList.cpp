#include<iostream>
using namespace std;

class doublyNode
{
    public:
    int data;
    doublyNode *next;
    doublyNode *prev;

    doublyNode(int d)
    {
        this->data = d;
        this->next = NULL;
        this->prev = NULL;
    }
};
