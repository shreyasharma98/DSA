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
class Stack {
    Node<T> *head;
    int size;		// number of elements prsent in stack

    public :

    Stack() {
        head = NULL;
        size = 0;
    }

    int getSize() {
        return size;
    }

    bool isEmpty() {
        return head == NULL;
    }

    void push(T element) {
        Node<T> *newnode = new Node<T>(element);
        newnode->next = head;
        head = newnode;
        size++;
    }

    T pop() {
        size--;
        Node<T> *delnode = head;
        head = head->next;
        return delnode->data;
    }

    T top() {
        // Return 0 if stack is empty. Don't display any other message
        return head->data;
    }



};
