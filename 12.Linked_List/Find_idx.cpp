#include<iostream>
#include "node.cpp"

using namespace std;
int indexOfNIter(node *head, int n) {
   node *temp = head;
    int i = 0;
    while(temp !=NULL)
    {
        if(temp->data == n)
        {
            return i;
        }
        else{
            i++;
            temp = temp->next;
        }
    }
    return -1;

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
    int n;
    cin >> n;
    cout << indexOfNIter(head, n);

}

