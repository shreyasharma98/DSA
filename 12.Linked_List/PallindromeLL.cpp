node* reverse(node *head)
{
    node *p=NULL,*c,*n=NULL;
    c = head;
    while(c!=NULL)
    {
        n = c->next;
        c->next = p;
        p = c;
        c = n;
    }
    return p;
}

int length(node *head) {
    node *temp = head;
    int n =  0;
    while(temp != NULL)
    {
        n++;
        temp = temp->next;
    }
    return n;
}

bool check_palindrome(node* head)
{
   node *h2 = head,*h1 = head;
   int len = length(head);
   for(int i =0;i<len/2;i++)
   {
        h2 = h2->next;
   }
   h2 = reverse(h2);
   while(h2!=NULL)
   {
       if(h2->data != h1->data)
       {
            return false;
       }
       h1 = h1->next;
       h2=h2->next;
   }
   return true;
}
