#include<iostream>
#include "Node.cpp"
using namespace std;

node* midpoint_linkedlist(node *head)
{
   node *slow = head,*fast = head->next;
    while(fast->next!=NULL || fast == NULL)
    {
        slow=slow->next;
        fast = fast->next->next;
    }
	head = slow;
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
    node*head=takeinput();
    node* mid=midpoint_linkedlist(head);
    cout<<mid->data;
    return 0;
}


