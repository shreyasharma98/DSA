
#include<iostream>
#include "Node.cpp"
using namespace std;

class Pair{
public:
    Node *head;
    Node *tail;
};
/*
Pair reverse_LL2(Node *head)
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

Node *reverse_linked_list_rec(Node *head)
{
    if(head == NULL || head->next == NULL)
    {
        return head;
    }
    Node *p = reverse_linked_list_rec(head->next);
    Node *tail = head->next;
    tail->next = head;
    head->next = NULL;
    return p;
    return reverse_LL2(head).head;
}
*/

Node *reverse_linked_list_rec(Node *head)
{
    if(head == NULL || head->next == NULL)
    {
        return head;
    }
    Node *p = reverse_linked_list_rec(head->next);
    Node *temp = p;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next = head;
    head->next = NULL;
    head = p;
    return head;
}



Node* takeinput() {
    int data;
    cin >> data;
    Node* head = NULL, *tail = NULL;
    while(data != -1){
        Node *newNode = new Node(data);
        if(head == NULL)                  {
            head = newNode;
            tail = newNode;
        }
        else{
            tail -> next = newNode;
            tail = newNode;
        }
        cin >> data;
    }
    return head;
}

void print(Node *head) {
    Node *temp = head;
    while(temp != NULL) {
        cout << temp -> data << " ";
        temp = temp -> next;
    }
    cout<<endl;
}

int main()
{
    Node* head=takeinput();
    head=reverse_linked_list_rec(head);
    print(head);
    return 0;
}

