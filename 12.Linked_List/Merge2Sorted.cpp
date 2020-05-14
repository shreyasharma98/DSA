#include<iostream>
#include "Node.cpp"
using namespace std;

Node* mergeTwoLLs(Node *head1, Node *head2) {
    Node *h1 = head1,*h2 = head2,*fhead = NULL,*ftail = NULL;
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

int main() {
    Node *head1 = takeinput();
    Node *head2 = takeinput();
    Node *head3 = mergeTwoLLs(head1, head2);
    print(head3);
    return 0;
}

