
#include<iostream>
#include "node.cpp"

using namespace std;
node* append_LinkedList(node* head,int n)
{
    int i = -n;
    node *temp = head;
    node *t = head;
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





/*int length(node *head) {
    node *temp = head;
    int n =  0;
    while(temp != NULL)
    {
        n++;
        temp = temp->next;
    }
    return n;
}


node* append_LinkedList(node* head,int n)
{
  int len = length(head);
    node *temp = head;
    node *tail = head;
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
int main()
{
    node* head=takeinput();
    int n;
    cin>>n;
    head=append_LinkedList(head,n);
    print(head);
    return 0;
}
