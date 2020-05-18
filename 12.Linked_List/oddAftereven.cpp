#include<iostream>
#include "Node.cpp"
using namespace std;
Node* arrange_LinkedList(Node* head)
{
    Node *temp=head,*odd=NULL,*even=NULL,*even_head = NULL,*odd_head=NULL;
    while(temp!=NULL)
    {
        if(temp->data % 2 != 0)
        {
            if(odd_head == NULL)
            {
                odd_head = temp;
                odd = temp;
            }
            else
            {
                odd->next = temp;
                odd = temp;
            }
        }
        else
        {
            if(even_head == NULL)
            {
                even_head = temp;
                even = temp;
            }
            else
            {
                even->next = temp;
                even = temp;
            }
        }
        temp = temp->next;
    }
    if(odd_head != NULL)
    {
        if(even_head == NULL)
         {
             odd->next = NULL;
             return odd_head;
         }

        even->next = NULL;
        odd->next = even_head;
        return odd_head;
    }
    return even_head;
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
    head=arrange_LinkedList(head);
    print(head);
    return 0;
}
