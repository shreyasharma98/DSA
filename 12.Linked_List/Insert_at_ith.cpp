
#include<iostream>
#include "node.cpp"

using namespace std;

node* insert(node *head , int i, int ele)
{
    node *newnode = new node(ele);
    node *temp = head;
    int ctr = 0;
    if(i == 0)
    {
        newnode->next = head;
        head = newnode;
    }
    while(ctr<i-1 && temp!= NULL)
    {
        temp =  temp->next;
        ctr++;
    }
    if(temp!= NULL){
    /*node *t = temp->next;
    temp ->next = newnode;
    newnode->next = t;*/

    newnode->next = temp->next;
    temp->next = newnode;
    }
    return head;
}
node* takeInput()
{
    int data;
    cin>>data;
    node *head = NULL;
    node *tail = NULL;
    while(data != -1)
    {
        node *newnode = new node(data);
        if(head == NULL)
        {
            head = newnode;
            tail = newnode;
        }
        else
        {
            tail->next = newnode;
            tail = tail->next;

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
    node *head = takeInput();
    int idx,element;
    cout<<"The Linked list looks like :\n";
    print(head);
    cin>>idx>>element;
    head = insert(head,idx,element);
    cout<<"The Linked list after insertion looks like :\n";
    print(head);
    return 0;
}

