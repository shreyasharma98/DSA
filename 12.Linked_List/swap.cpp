#include<iostream>
using namespace std;
#include "circular.cpp"
Node* find(Node *head ,int x)
{
    Node *temp = head;
    int ctr = 1;
    while(ctr<x)
    {
        temp = temp->next;
        ctr++;
    }
    return temp;
}

Node* swap_Nodes(Node *head,int i,int j)
{
    if(i == 0)
    {
        Node *a = head;
        Node *pNode = find(head,j);
        Node *b = pNode->next;
        pNode->next = a;
        Node *temp = b->next;
        b->next = a->next;
        a->next = temp;
        head = b;
    }
    else if(j==0)
    {
        Node *a = head;
        Node *pNode = find(head,i);
        Node *b = pNode->next;
        pNode->next = a;
        Node *temp = b->next;
        b->next = a->next;
        a->next = temp;
        head = b;
    }
        else{
        int ctr = 1;
        Node *temp = head,*p1=NULL,*p2=NULL;
        while(ctr<=max(i,j))
        {
            if(ctr == i)
            {
                p1=temp;
            }
            else if(ctr == j)
            {
                p2 = temp;
            }
            temp = temp->next;
            ctr++;
        }
        Node *c1 = p1->next,*c2 = p2->next;
        p1->next = c2;
        p2->next = c1;
        Node *t = c2->next;
        c2->next = c1->next;
        c1->next = t;
        }
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
int main()
{
    Node* head=takeinput();
    int m,n;
    cin>>m >> n;
    head= swap_Nodes(head,m,n);
   print(head);
    return 0;
}
