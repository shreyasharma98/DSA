#include<iostream>
using namespace std;
#include "circular.cpp"

Node* skipMdeleteN(Node  *head, int M, int N) {

    Node *temp1=head;
    while(temp1 != NULL)
    {
        int ctr1 = 0, ctr2=0;
        while(ctr1<M-1)
        {
            temp1=temp1->next;
            ctr1++;
        }
        Node *temp2=temp1->next;
        while(ctr2<=N-1)
        {
            if(temp2 == NULL){break;}
            temp2=temp2->next;
            ctr2++;
        }
        temp1->next = temp2;
        temp1 = temp1->next;
    }
    return head;
}
Node* takeinput(){
    int data;
    cin>>data;
    Node* head=NULL,*tail=NULL;
    while(data!=-1){
        Node *newnode=new Node(data);
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
    int m,n;
    cin>>m >> n;
    head= skipMdeleteN(head,m,n);
    print(head);
    return 0;
}
