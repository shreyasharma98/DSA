#include<iostream>
#include "Node.cpp"
class Pair
{
public:
    node *head;
    node *tail;
};
Pair reverse(node* head)
{
    if(head == NULL || head->next == NULL)
    {
        Pair ans;
        ans.head=head;
        ans.tail = head;
        return ans;
    }
    Pair small_ans = reverse(head->next);
    small_ans.tail->next=head;
    head->next = NULL;
    Pair ans;
    ans.head = small_ans.head;
    ans.tail = head;
    return ans;

}
node* kReverse(node*head,int n)
{
    if(head == NULL || head->next == NULL)
    {
        return head;
    }
    node *h1=head,*t1 = head;
    int i = 1;
    while(i!=n)
    {
        t1=t1->next;
        if(t1 == NULL)
        {
            return kReverse(h1,i);
        }
        i++;
    }
    node *h2 = t1->next;
    t1->next = NULL;
    Pair ans = reverse(h1);
    node *h3 = kReverse(h2,n);
    ans.tail->next = h3;
    return ans.head;
}
