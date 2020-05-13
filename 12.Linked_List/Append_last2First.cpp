
#include<iostream>
#include "Node.cpp"

using namespace std;
Node* append_LinkedList(Node* head,int n)
{
    int i = -n;
    Node *temp = head;
    Node *t = head;
    while(temp->next != NULL)
    {
        if(i>=0)
        {
            t=t->next;
        }
        i++;
        temp= temp->next;
    }
    temp->next = head;
    head = t->next;
    t->next = NULL;
    
    return head;
}





/*int length(Node *head) {
    Node *temp = head;
    int n =  0;
    while(temp != NULL)
    {
        n++;
        temp = temp->next;
    }
    return n;
}


Node* append_LinkedList(Node* head,int n)
{
  int len = length(head);
    Node *temp = head;
    Node *tail = head;
    while(tail->next != NULL)
    {
      tail = tail->next;
    }
    tail->next = temp;
    int i =0;
    while(i<len-n-1)
    {
        temp = temp->next;
        i++;
    }
    head = temp->next;
    temp->next = NULL;
    return head;
}*/
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
int main()
{
    Node* head=takeinput();
    int n;
    cin>>n;
    head=append_LinkedList(head,n);
    print(head);
    return 0;
}
