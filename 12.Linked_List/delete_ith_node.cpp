

#include<iostream>
#include "node.cpp"

using namespace std;

node* delete_(node *head , int i)
{
    node *temp = head;
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
   node *t = temp->next;
   temp->next = t->next;
   delete t;}
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
    int idx;
    cout<<"The Linked list b4 deletion :\n";
    print(head);
    cin>>idx;
    head = delete_(head,idx);
    cout<<"The Linked list after deletion looks like :\n";
    print(head);
    return 0;
}

