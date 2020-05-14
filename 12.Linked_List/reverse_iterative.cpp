#include<iostream>
#include "Node.cpp"
using namespace std;

Node *reverse_linked_list_itr(Node *head)
{
    Node *prev = NULL, *curr = head;
    Node *next = curr->next;
    while(curr->next!=NULL)
    {
        curr->next=prev;
        prev = curr;
        curr = next;
        next = next->next;

    }
    curr->next = prev;
    return curr;
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
    head=reverse_linked_list_itr(head);
    print(head);
    return 0;
}

