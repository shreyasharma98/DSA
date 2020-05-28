#include<iostream>
#include "Node.cpp"
class Pair
{
public:
    node *head;
    node *tail;
};
Pair reverse(node* head)
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
node* kReverse(node*head,int n)
{
    if(head == NULL || head->next == NULL)
    {
        return head;
    }
    node *h1=head,*t1 = head;
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
    node *h2 = t1->next;
    t1->next = NULL;
    Pair ans = reverse(h1);
    node *h3 = kReverse(h2,n);
    ans.tail->next = h3;
    return ans.head;
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
    int n;
    cin>>n;
    head=kReverse(head,n);
    print(head);
    return 0;
}
