typedef Node* btptr;
Node *convertExpression(string s,int i)
{
 int n=s.length();
 stack<btptr>st;
 char temp=' ';
 btptr root=NULL;
 for(int i=0;i<n;i++)
 {
     if(s[i]!='?'&&s[i]!=':')
      temp=s[i];
     else
     {
         if(root==NULL)
         {
             root=new Node(temp);
             st.push(root);
         }
         else
         {
             btptr t=st.top();
            while(t->left&&t->right)
            {
             t=st.top();
             st.pop();
             }
             if(t->left==NULL)
                {
                    t->left=new Node(temp);
                    if(s[i]=='?')
                      st.push(t->left);
                }    
            else if(t->right==NULL)
                {
                    t->right=new Node(temp);
                    if(s[i]=='?')
                      st.push(t->right);
                }    
         }
         temp=' ';
     }
    
 }
  if(!st.empty())
     {
         btptr y=st.top();
         while(y->left&&y->right)
         {
             y=st.top();
             st.pop();
         }
         if(y->left==NULL)
           y->left=new Node(temp);
         else if(y->right==NULL)
           y->right=new Node(temp);
     }
 return root;
}
