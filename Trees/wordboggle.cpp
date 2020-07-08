#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
struct tnode
{
    tnode *child[26];
    int endofword;
};
typedef tnode* trnode;
trnode getnode()
{
    trnode n=new tnode();
    for(int i=0;i<26;i++)
      n->child[i]=NULL;
    n->endofword=0;
    return n;
}
trnode insert(trnode &root,string s)
{
    if(root==NULL)
       root=getnode();
       trnode temp=root;
      for(int i=0;i<s.length();i++)
      {
          int k=toupper(s[i])-'A';
          if(temp->child[k]==NULL)
           temp->child[k]=getnode();
           temp=temp->child[k];
      }
      temp->endofword++;
      return root;
}
bool search(trnode root,string s)
{
   trnode temp=root;
   for(int i=0;i<s.length();i++)
   {
       int k=toupper(s[i])-'A';
       if(temp->child[k]==NULL)
          return false;
       temp=temp->child[k];
   }
   if(temp->endofword>0)
    return true;
    else 
      return false;
}
int xdir[]={-1,-1,1,1,0,0,1,-1};
int ydir[]={-1,1,1,-1,-1,1,0,0};
void dfs(vector<vector<char>>bo,string temp,int i,int j,int a,int b,trnode root,vector<vector<int>>&vis,set<string>&ans)
{
    if(i<0||j<0||i>=a||j>=b)
        return;
    if(vis[i][j]==1)
       return;
      // cout<<temp<<" "<<bo[i][j]<<" "<<"\n";
    if(root->endofword>0)
       {
       	ans.insert(temp);
	   }
    if(root->child[toupper(bo[i][j])-'A']==NULL)
      return;
     if(root->child[toupper(bo[i][j])-'A']->endofword>0)
       ans.insert(temp+bo[i][j]);
    vis[i][j]=1;
   
     for(int l=0;l<8;l++)
     {
         int x=i+xdir[l],y=j+ydir[l];
         dfs(bo,temp+bo[i][j],x,y,a,b,root->child[toupper(bo[i][j])-'A'],vis,ans);
     }
}
void boggle(vector<string>d,int n,vector<vector<char>>bo,int a,int b,set<string>&ans)
{
    trnode root=NULL;
    for(int i=0;i<n;i++)
     insert(root,d[i]);
   /* for(int i=0;i<n;i++)
      cout<<search(root,d[i]);
     cout<<"kfekje\n";*/
    // string temp="";
    for(int i=0;i<a;i++)
     {
         for(int j=0;j<b;j++)
         {
             vector<vector<int>>vis(a,vector<int>(b,0));
             string temp="";
           
             dfs(bo,temp,i,j,a,b,root,vis,ans);
         }
     }     
}
int main() 
{
	int t,a,m,n;
	cin>>t;
	while(t--)
	{
	    cin>>a;
	    vector<string>d(a);
	    for(int i=0;i<a;i++)
	      cin>>d[i];
	      cin>>m>>n;
	    vector<vector<char>>c(m,vector<char>(n));
	    for(int i=0;i<m;i++)
	    {
	        for(int j=0;j<n;j++)
	          cin>>c[i][j];
	    }
	    set<string>ans;
	    boggle(d,a,c,m,n,ans);
	    if(ans.size()==0)
	      cout<<-1;
	    for(auto i=ans.begin();i!=ans.end();i++)
	      cout<<*i<<" ";
	      cout<<"\n";
	}
	return 0;
}
