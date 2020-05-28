#include<iostream>
using namespace std;
#include "circular.cpp"

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
           tail = newNode;
        }
        cin>>data;
    }
    tail->next = head;
    return head;
}
void print(Node *head)
{
    Node *temp = head->next;
    cout<<head->data<<" ";
    while(temp!=head)
    {
        cout<<temp->data<<"  ";
        temp = temp->next;
    }
    cout<<endl;
}
int main()
{
    Node *head = takeInput();
    print(head);

     //insert_at_head
    int x;
    cout<<"Enter the no. you want to insert at head : ";
    cin>>x;
    Node *Node = new Node(x);

    //insert_at_tail
    cout<<"Enter the no. you want to insert at head : ";
    cin>>x;
    doublyNode *nNode = new doublyNode(x);
    ans.tail->next = nNode;
    nNode->prev = ans.tail;
    ans.tail = nNode;
        cout<<"from head :"<<endl;
    print_head(ans.head);
    cout<<"from tail :"<<endl;
    print_tail(ans.tail);
}


