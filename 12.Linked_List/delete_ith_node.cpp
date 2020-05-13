

#include<iostream>
#include "Node.cpp"

using namespace std;

Node* delete_(Node *head , int i)
{
    Node *temp = head;
    int ctr = 0;
    if(i == 0)
    {
        head = temp->next;
    }
   while(temp!=NULL&&ctr<i-1)
   {
       ctr++;
       temp = temp->next;
   }
   if(temp->next!=NULL){
   Node *t = temp->next;
   temp->next = t->next;
   delete t;}
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
    int idx;
    cout<<"The Linked list b4 deletion :\n";
    print(head);
    cin>>idx;
    head = delete_(head,idx);
    cout<<"The Linked list after deletion looks like :\n";
    print(head);
    return 0;
}

