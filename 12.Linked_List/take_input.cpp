#include<iostream>
#include "Node.cpp"

using namespace std;
Node* takeInput()
{
    int data;
    cin>>data;
    Node *head = NULL;
    while(data != -1)
    {
        Node *newNode = new Node(data);
        if(head == NULL)
        {
            head = newNode;
        }
        else
        {
            Node *temp = head;
            while(temp->next!=NULL)
            {
                temp = temp->next;
            }
            temp->next = newNode;
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
int main()
{
    Node *head = takeInput();
    print(head);
    return 0;
}
