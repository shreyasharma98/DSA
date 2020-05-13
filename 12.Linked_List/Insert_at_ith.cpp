
#include<iostream>
#include "Node.cpp"

using namespace std;

Node* insert(Node *head , int i, int ele)
{
    Node *newNode = new Node(ele);
    Node *temp = head;
    int ctr = 0;
    if(i == 0)
    {
        newNode->next = head;
        head = newNode;
    }
    while(ctr<i-1 && temp!= NULL)
    {
        temp =  temp->next;
        ctr++;
    }
    if(temp!= NULL){
    /*Node *t = temp->next;
    temp ->next = newNode;
    newNode->next = t;*/

    newNode->next = temp->next;
    temp->next = newNode;
    }
    return head;
}
Node* takeInput()
{
    int data;
    cin>>data;
    Node *head = NULL;
    Node *tail = NULL;
    while(data != -1)
    {
        Node *newNode = new Node(data);
        if(head == NULL)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = tail->next;

        }
        cin>>data;
    }
    return head;
}
void print(Node *head)
    {
        Node *temp = head;
        while(temp!=NULL)
        {
            cout<<temp->data<<"  ";
            temp = temp->next;
        }
        cout<<endl;
    }
int main() {
    Node *head = takeInput();
    int idx,element;
    cout<<"The Linked list looks like :\n";
    print(head);
    cin>>idx>>element;
    head = insert(head,idx,element);
    cout<<"The Linked list after insertion looks like :\n";
    print(head);
    return 0;
}

