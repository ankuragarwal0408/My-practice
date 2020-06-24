/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    typedef ListNode* lptr;
lptr rev(lptr &node,lptr &prev,lptr &h)
{
    if(node==NULL)
    return prev;
    node=rev(node->next,node,h);
    if(h==NULL)
      h=node;
    node->next=prev;
    prev->next=NULL;
    return prev;
}

void reverseBetween(lptr &head, int st, int end) 
{
    if(head==NULL)
   return;
   if(head->next==NULL)
   return;
   int i=1;
   lptr prev=NULL,start=head;
   while(i<st)
   {
       prev=start;
       start=start->next;
       i++;
   }
   if(prev!=NULL)
   prev->next=NULL;
   lptr es=start;
   while(i<end)
   {
       es=es->next;
       i++;
   }
   lptr next=es->next;
   es->next=NULL;
   lptr h=NULL;
  lptr y=rev(start,start,h);
  if(prev!=NULL)
  prev->next=h;
  else
  head=h;
  start->next=next;
}
ListNode* reverseKGroup(ListNode* head, int k) 
{
  if(head==NULL||k==1)
       return head;
 int len=0;
    lptr temp=head;
    while(temp)
    {
        temp=temp->next;
        len++;
    }
    int h=len/k;
    int st=1,en=k;
    for(int i=0;i<h;i++)
    {
        reverseBetween(head,st,en);
        st=k+st;
        en=en+k;
    }
    return head;
}
};
