#include<iostream>
#include "Node.cpp"
using namespace std;

Node* eliminate_duplicate(Node* head)
{
   Node *temp1 = head;
    Node *temp2 = temp1->next;
    if(head == NULL || head->next == NULL)
    {
        return head;
    }
    while(temp2!=NULL)
    {
        if(temp1->data == temp2->data)
        {
            temp1->next = temp2->next;
            temp2=temp2->next;
        }
        else{
            temp1=temp2;
            temp2=temp2->next;
        }
    }

    return head;
}
Node* takeinput(){
    int data;
    cin>>data;
    Node* head=NULL,*tail=NULL;
    while(data!=-1){
        Node *newnode=new node(data);
        if(head==NULL)                  {
            head=newnode;
            tail=newnode;
        }
        else{
            tail->next=newnode;
            tail=newnode;
        }
        cin>>data;
    }
    return head;
}
void print(Node *head)
{
    
    
    Node*temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
int main(){
    Node* head=takeinput();
    head=eliminate_duplicate(head);
    print(head);
    return 0;
}

