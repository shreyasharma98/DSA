
#include<iostream>
#include "node.cpp"
using namespace std;


void printIthnode(node *head, int i) {
    node *temp = head;
    int x = 0;
    while(temp != NULL)
    {
        if(x == i)
        {
            cout<<temp->data;
            return;
        }
        else
        {
            x++;
            temp = temp->next;
        }
    }
}

node* takeInput()
{
    int data;
    cin>>data;
    node *head = NULL;
    while(data != -1)
    {
        node *newnode = new node(data);
        if(head == NULL)
        {
            head = newnode;
        }
        else
        {
            node *temp = head;
            while(temp->next!=NULL)
            {
                temp = temp->next;
            }
            temp->next = newnode;
        }
        cin>>data;
    }
    return head;
}
void print(node *head)
    {
        node *temp = head;
        while(temp!=NULL)
        {
            cout<<temp->data<<"  ";
            temp = temp->next;
        }
        cout<<endl;
    }
int main() {
    node *head = takenput();
    int pos;
    cin >> pos;
    printIthnode(head, pos);
    return 0;
}
