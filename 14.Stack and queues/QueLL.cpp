#include<iostream>
using namespace std;

template <typename T>
class Node {
    public :
    T data;
    Node<T> *next;

    Node(T data) {
        this -> data = data;
        next = NULL;
    }
};

template <typename T>
class Queque {
    Node<T> *head;
    Node<T> *NextIndex;
    int size;		// number of elements prsent in stack

    public :

    Queue() {
        head = NULL;
        NextIndex = NULL;
        size = 0;
    }

    int getSize() {
        return size;
    }

    bool isEmpty() {
        return head == NULL;
    }

    void enque(T element) {
        Node<T> *newnode = new Node<T>(element);
        if(head == NULL)
        {
            head = newnode;
            NextIndex = newNode;
        }
        else
        {
                NextIndex->next = newnode;
                NextIndex = NextIndex->next
        }
        size++;
    }

    T deque() {
        size--;
        Node<T> *delnode = head;
        head = head->next;
        return delnode->data;
    }

    T front() {
        // Return 0 if stack is empty. Don't display any other message
        return head->data;
    }



};
