#include<iostream>
using namespace std;
#include "doubly_linkedList.cpp"
class doublly
{
public :
    doublyNode *head;
    doublyNode *tail;
    doublly(doublyNode *h,doublyNode *t)
    {
        this->head = h;
        this->tail = t;
    }
};

doublly takeInput()
{
    int data;
    cin>>data;
    doublyNode *head = NULL;
    doublyNode *tail = NULL;
    while(data != -1)
    {
        doublyNode *node = new doublyNode(data);

        if(head == NULL)
        {
            head = node;
            tail = node;
        }
        else
        {
            doublyNode *temp = tail;
            temp->next = node;
            temp = temp->next;
            temp->prev = tail;
            tail = temp;
        }
        cin>>data;
    }
    doublly d1(head,tail);
    return d1;
}
void print_head(doublyNode *head)
    {
       doublyNode  *temp = head;
        while(temp!=NULL)
        {
            cout<<temp->data<<"  ";
            temp = temp->next;
        }
        cout<<endl;
    }
void print_tail(doublyNode *tail)
    {
       doublyNode  *temp = tail;
        while(temp!=NULL)
        {
            cout<<temp->data<<"  ";
            temp = temp->prev;
        }
        cout<<endl;
    }


int main()
{
    doublly ans = takeInput();
    cout<<"Accesing from head :"<<endl;
    print_head(ans.head);
    cout<<"Accesing from tail :"<<endl;
    print_tail(ans.tail);

    //insert_at_head
    int x;
    cout<<"Enter the no. you want to insert at head : ";
    cin>>x;
    doublyNode *node = new doublyNode(x);
    node->next = ans.head;
    ans.head->prev =node;
    ans.head = node;
    cout<<"from head :"<<endl;
    print_head(ans.head);
    cout<<"from tail :"<<endl;
    print_tail(ans.tail);

    //insert_at_tail
    cout<<"Enter the no. you want to insert at head : ";
    cin>>x;
    doublyNode *nnode = new doublyNode(x);
    ans.tail->next = nnode;
    nnode->prev = ans.tail;
    ans.tail = nnode;
        cout<<"from head :"<<endl;
    print_head(ans.head);
    cout<<"from tail :"<<endl;
    print_tail(ans.tail);

}


