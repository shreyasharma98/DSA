#include<iostream>
#include "Node.cpp"
using namespace std;

Node* midpoint_linkedlist(Node *head)
{
   Node *slow = head,*fast = head->next;
    while(fast->next!=NULL || fast == NULL)
    {
        slow=slow->next;
        fast = fast->next->next;
    }
	head = slow;
    return head;
}
Node* takeinput(){
    int data;
    cin>>data;
    Node* head=NULL,*tail=NULL;
    while(data!=-1){
        Node *newNode=new Node(data);
        if(head==NULL)                  {
            head=newNode;
            tail=newNode;
        }
        else{
            tail->next=newNode;
            tail=newNode;
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
    Node*head=takeinput();
    Node* mid=midpoint_linkedlist(head);
    cout<<mid->data;
    return 0;
}


