typedef ListNode *lptr;
lptr  merging(ListNode* A, ListNode* B) 
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
void frontbacksplit(lptr h,lptr &front,lptr &back)
{
    lptr s;
    lptr f;
    s=h;
    f=h->next;
    while(f!=NULL)
    {
        f=f->next;
        if(f!=NULL)
        {
            s=s->next;
            f=f->next;
        }
    }
    front=h;
    back=s->next;
    s->next=NULL;
}
void mergesort(lptr &head)
{
    lptr a=NULL,b=NULL;
    if(head==NULL||head->next==NULL)
     return;
    frontbacksplit(head,a,b);
    mergesort(a);
    mergesort(b);
    head=merging(a,b);
}


ListNode* Solution::sortList(ListNode* A) 
{
    if(A==NULL)
     return A;
     mergesort(A);
    return A;
}
