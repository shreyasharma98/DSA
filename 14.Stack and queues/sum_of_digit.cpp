#include<iostream>
using namespace std;
class Node{
public:
    int data;
    Node *next;
    Node(int data){
        this -> data = data;
        this -> next = NULL;
    }
};

Node* NextLargeNumber(Node *head) {
    Node *tail = head;
    while(tail->next!=NULL)
    {
        tail = tail->next;
    }
    if(tail->data < 9)
    {
        tail->data+=1;
        return head;
    }

   while(tail->data >= 9)
   {
    Node *temp =head;
    while(temp->next!=tail)
    {
        temp=temp->next;
    }
    tail->data = 0;
    tail = temp;
    if(tail == head)
   {
       tail->data = 0;
       Node *newNode = new Node(1);
       newNode->next = tail;
       head = newNode;
       return head;
   }
   }

   tail->data+=1;

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

    head = NextLargeNumber(head);
    print(head);
    return 0;
}



