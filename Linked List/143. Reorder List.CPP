static int x = []() { std::ios::sync_with_stdio(false); cin.tie(nullptr); return 0; }();
class Solution 
{
public:
    typedef ListNode* lptr;
    void reorderList(ListNode* head) 
    {
        stack<lptr>st;
        lptr node=head;
        if(head==NULL)
            return;
        while(node!=NULL)
        {
            st.push(node);
            node=node->next;
        }
        lptr temp=NULL,curr=head;
        while(!st.empty()&&curr!=st.top())
        {
            temp=curr->next;
            curr->next=st.top();
            if(st.top()==temp)
                 break;
            st.top()->next=temp;
            curr=temp;
            st.pop();
        }
        st.top()->next=NULL;
        return;
    }
};
