#include<iostream>
#include "Node.cpp"
using namespace std;
int length(Node *head) {
    Node *temp = head;
    int n =  0;
    while(temp != NULL)
    {
        n++;
        temp = temp->next;
    }

    return n;
}
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
    cout << length(head);
    return 0;
}
