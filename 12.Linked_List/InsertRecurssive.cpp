#include<iostream>
#include "node.cpp"
using namespace std;

node* insertnodeRec(node *head, int i, int data) {
    if(head == NULL)
    {
        return head;
    }
    if(i == 0)
    {
         node *n = new node(data);
         n->next = head;
         head = n;
         return head;
    }
    head->next = insertnodeRec(head->next,i-1,data);
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

int main() {
    node *head = takeinput();
    int pos, data;
    cin >> pos >> data;
    head = insertnodeRec(head, pos, data);
    print(head);
    return 0;
}
