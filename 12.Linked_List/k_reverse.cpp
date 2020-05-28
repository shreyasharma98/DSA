#include<iostream>
#include "Node.cpp"
class Pair
{
public:
    Node *head;
    Node *tail;
};
Pair reverse(Node* head)
{
    if(head == NULL || head->next == NULL)
    {
        Pair ans;
        ans.head=head;
        ans.tail = head;
        return ans;
    }
    Pair small_ans = reverse(head->next);
    small_ans.tail->next=head;
    head->next = NULL;
    Pair ans;
    ans.head = small_ans.head;
    ans.tail = head;
    return ans;

}
Node* kReverse(Node*head,int n)
{
    if(head == NULL || head->next == NULL)
    {
        return head;
    }
    Node *h1=head,*t1 = head;
    int i = 1;
    while(i!=n)
    {
        t1=t1->next;
        if(t1 == NULL)
        {
            return kReverse(h1,i);
        }
        i++;
    }
    Node *h2 = t1->next;
    t1->next = NULL;
    Pair ans = reverse(h1);
    Node *h3 = kReverse(h2,n);
    ans.tail->next = h3;
    return ans.head;
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
    int n;
    cin>>n;
    head=kReverse(head,n);
    print(head);
    return 0;
}
