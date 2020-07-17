typedef ListNode* lptr;
ListNode* Solution::reverseBetween(ListNode* A, int B, int C) 
{
    int cnta=1;
    lptr curr=A,prev=A,nxt=A->next;
    lptr head=NULL;
    while(cnta<B)
    {
        prev=curr;
        curr=curr->next;
        nxt=nxt->next;
        cnta++;
    }
    head=curr;
    prev->next=NULL;
    while(cnta<C)
    {
        lptr y=nxt->next;
        nxt->next=curr;
        curr=nxt;
        nxt=y;
        cnta++;
    }
    prev->next=curr;
    head->next=nxt;
    if(B==1)
      return curr;
    return A;
}
