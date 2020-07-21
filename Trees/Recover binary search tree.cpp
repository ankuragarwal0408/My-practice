class Solution {
public:
 typedef TreeNode* btptr;
void recoverTree(btptr &root) 
{
    vector<btptr> res;
    if(root==NULL)
    return;
   btptr first=NULL,second=NULL,pre=NULL,current=root;
    while(current!=NULL)
    {
        if(pre!=NULL&&current->val<pre->val)
        {
            if(first==NULL)  first=pre;
            second=current;
        }
        if(current->left)
        {
            btptr pred=current->left;
            while(pred->right!=NULL&&pred->right!=current)
              pred=pred->right;
            if(pred->right==NULL)
            {
                pred->right=current;
                current=current->left;
            }
            else
            {
                pred->right=NULL;
                pre=current;
                current=current->right;
            }
        }
        else
        {
            pre=current;
            current=current->right;
        }
    }
    if(first&&second)
         swap(first->val,second->val);
    return;
}  
};
