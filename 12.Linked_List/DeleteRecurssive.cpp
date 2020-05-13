#include<iostream>
#include "Node.cpp"
using namespace std;

Node* deleteNodeRec(Node *head, int i) {
   if(head == NULL)
    {
        return head;
    }
    if(i == 0)
    {
         return head->next;
    }
    head->next = deleteNodeRec(head->next,i-1);
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
    int pos;
    cin >> pos;
    head = deleteNodeRec(head, pos);
    print(head);
    return 0;
}

