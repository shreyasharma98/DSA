#include<iostream>
#include "node.cpp"
using namespace std;

node* eliminate_duplicate(node* head)
{
   node *temp1 = head;
    node *temp2 = temp1->next;
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
node* takeinput(){
    int data;
    cin>>data;
    node* head=NULL,*tail=NULL;
    while(data!=-1){
        node *newnode=new node(data);
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
void print(node *head)
{


    node*temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
int main(){
    node* head=takeinput();
    head=eliminate_duplicate(head);
    print(head);
    return 0;
}

