#include<iostream>
#include "node.cpp"
using namespace std;

node* deletenodeRec(node *head, int i) {
   if(head == NULL)
    {
        return head;
    }
    if(i == 0)
    {
         return head->next;
    }
    head->next = deletenodeRec(head->next,i-1);
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
    int pos;
    cin >> pos;
    head = deletenodeRec(head, pos);
    print(head);
    return 0;
}

