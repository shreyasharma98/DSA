
#include<iostream>
using namespace std;
#include "circular.cpp"
bool check(node *head)
{
    node *temp1 = head;
    node *temp2 = temp1->next;
    while(temp2!= NULL)
    {
        if(temp1->data > temp2->data)
        {
            return false;
        }
        temp1=temp2;
        temp2=temp2->next;
    }
    return true;
}
node* bubble_sort_LinkedList_itr(node* head)
{
    bool ch;
    ch = check(head);
    while(ch == false)
    {
        node *curr = head,*prev = NULL;
       while(curr->next != NULL)
       {
           node *next = curr->next;
           if(curr->data > next->data)
           {
               if(prev == NULL)
               {
                   curr->next = next->next;
                   next->next = curr;
                   prev = next;
                   head = prev;
               }
               else
               {
                   curr->next = next->next;
                   prev->next = next;
                   next->next = curr;
                   prev = next;
               }
           }
           else
           {
                prev = curr;
                curr= curr->next;
           }
       }
       ch = check(head);
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
int main()
{
    node* head=takeinput();
    head=bubble_sort_LinkedList_itr(head);
    print(head);
}

