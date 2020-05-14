
#include<iostream>
#include "node.cpp"
using namespace std;

class Pair{
public:
    node *head;
    node *tail;
};
/*
Pair reverse_LL2(node *head)
{
    if(head == NULL || head->next == NULL)
    {
        Pair ans;
        ans.head=head;
        ans.tail = head;
        return ans;
    }
    Pair small_ans = reverse_LL2(head->next);
    small_ans.tail->next=head;
    head->next = NULL;
    Pair ans;
    ans.head = small_ans.head;
    ans.tail = head;
    return ans;
}

node *reverse_linked_list_rec(node *head)
{
    if(head == NULL || head->next == NULL)
    {
        return head;
    }
    node *p = reverse_linked_list_rec(head->next);
    node *tail = head->next;
    tail->next = head;
    head->next = NULL;
    return p;
    return reverse_LL2(head).head;
}
*/

node *reverse_linked_list_rec(node *head)
{
    if(head == NULL || head->next == NULL)
    {
        return head;
    }
    node *p = reverse_linked_list_rec(head->next);
    node *temp = p;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next = head;
    head->next = NULL;
    head = p;
    return head;
}



node* takeinput() {
    int data;
    cin >> data;
    node* head = NULL, *tail = NULL;
    while(data != -1){
        node *newnode = new node(data);
        if(head == NULL)                  {
            head = newnode;
            tail = newnode;
        }
        else{
            tail -> next = newnode;
            tail = newnode;
        }
        cin >> data;
    }
    return head;
}

void print(node *head) {
    node *temp = head;
    while(temp != NULL) {
        cout << temp -> data << " ";
        temp = temp -> next;
    }
    cout<<endl;
}

int main()
{
    node* head=takeinput();
    head=reverse_linked_list_rec(head);
    print(head);
    return 0;
}

