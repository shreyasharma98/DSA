#include<iostream>
#include "Node.cpp"

using namespace std;

int length(Node *head) {
    if(head->next == NULL)
    {
        return 1;
    }
    head = head->next;
    return 1+length(head);
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
    int pos;
    cin >> pos;
    cout << length(head);
    return 0;
}
