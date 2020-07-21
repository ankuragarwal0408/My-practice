/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<int> Solution::solve(TreeNode* A) 
{
    vector<int> ans;
    queue<TreeNode*> s;
    TreeNode *curr=A;
    while(curr!=NULL || !s.empty()){
        if(curr==NULL){
            curr=s.front();
            s.pop();
        }
        ans.push_back(curr->val);
        if(curr->left){
            s.push(curr->left);
        }
        curr=curr->right;
    }
    return ans;
}
