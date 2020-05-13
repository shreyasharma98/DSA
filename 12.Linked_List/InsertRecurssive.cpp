#include<iostream>
#include "Node.cpp"
using namespace std;

Node* insertNodeRec(Node *head, int i, int data) {
    if(head == NULL)
    {
        return head;
    }
    if(i == 0)
    {
         Node *n = new Node(data);
         n->next = head;
         head = n;
         return head;
    }
    head->next = insertNodeRec(head->next,i-1,data);
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

int main() {
    Node *head = takeinput();
    int pos, data;
    cin >> pos >> data;
    head = insertNodeRec(head, pos, data);
    print(head);
    return 0;
}
