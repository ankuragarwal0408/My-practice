typedef ListNode *lptr;
ListNode* Solution::mergeTwoLists(ListNode* A, ListNode* B) 
{
    lptr a=A,b=B;
    lptr n=(A->val<=B->val)?a:b;
    while(a!=NULL&&b!=NULL)
    {
        lptr preva=a;
        while(a!=NULL&&b!=NULL&&a->val<=b->val)
        {
            preva=a;
            a=a->next;
        }
        if(preva!=a)
          preva->next=b;
        lptr prevb=b;
        while(a!=NULL&&b!=NULL&&a->val>b->val)
        {
            prevb=b;
            b=b->next;
        }
        if(prevb!=b)
          prevb->next=a;
    }
    return n;
}
