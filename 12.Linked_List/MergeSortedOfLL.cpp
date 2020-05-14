#include<iostream>
#include "Node.cpp"
using namespace std;

node* merge(node *head1, node *head2) {
    node *h1 = head1,*h2 = head2,*fhead = NULL,*ftail = NULL;
    if(h1->data < h2->data)
    {
        fhead = h1;
        ftail = h1;
        h1=h1->next;
    }
    else
    {
        fhead = h2;
        ftail = h2;
        h2 = h2->next;
    }
    while(h1 != NULL && h2 != NULL)
    {
        if(h1->data < h2->data)
        {
            ftail->next = h1;
            ftail = h1;
            h1 = h1->next;
        }
        else
        {
            ftail->next = h2;
            ftail = h2;
            h2 = h2->next;
        }
    }
    if(h1 == NULL)
    {
        ftail->next = h2;
    }
    else
    {
        ftail->next = h1;
    }
    return fhead;
}

void divide(node *head , node** h1 , node** h2)
{
    node *slow = head,*fast = head->next;
    while(fast != NULL)
    {
        fast = fast->next;
        if(fast!= NULL)
        {
            slow=slow->next;
            fast = fast->next;
        }

    }
	*h1 = head;
	*h2 = slow->next;
	slow->next = NULL;
}
node* mergeSort(node *head)
{
    if(head==NULL  || head->next==NULL)
    {
        return head;
    }
    node *h1 ,*h2;
    divide(head,&h1,&h2);
    node *n1 = mergeSort(h1);
    node *n2 = mergeSort(h2);
    return merge(n1,n2);
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
int main()
{
    node* head=takeinput();
    head= mergeSort(head);
    print(head);
    return 0;
}
