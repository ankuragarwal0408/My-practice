#include <bits/stdc++.h>
#define pb push_back
#define ll long long int
#define pii pair<int,int>
#define mii map<int,int>
#define f first
#define s second
#define mp make_pair
# define INF 0x3f3f3f3f 
using namespace std;
struct node
{
	int data;
	int wt;
};
void farthestdist(int src,vector<vector<node>>&adj,int W,int V)
{
	vector<pair<int, list<int>::iterator> > dist(V); 
    for (int i = 0; i < V; i++) 
        dist[i].first = INF; 
    list<int> B[W * V + 1]; 
  
    B[0].push_back(src); 
    dist[src].first = 0; 
  
    // 
    int idx = 0; 
    while (1) 
    { 
   
        while (B[idx].size() == 0 && idx < W*V) 
            idx++; 
  
        if (idx == W * V) 
            break; 
  
        int u = B[idx].front(); 
        B[idx].pop_front(); 
  
    
        for (auto i = adj[u].begin(); i != adj[u].end(); ++i) 
        { 
            int v = (*i).data; 
            int weight = (*i).wt; 
  
            int du = dist[u].first; 
            int dv = dist[v].first; 
  
        
            if (dv > du + weight) 
            { 
              
                if (dv != INF) 
                    B[dv].erase(dist[v].second); 
  
                dist[v].first = du + weight; 
                dv = dist[v].first; 
   
                B[dv].push_front(v); 
  
                dist[v].second = B[dv].begin(); 
            } 
        } 
    } 
    int m=INT_MIN;
    for(int i=0;i<V;i++)
    {
    	if(dist[i].f!=INF)
    	m=max(dist[i].f,m);
	}
    if(m==INT_MIN)
      cout<<0<<" "<<1<<"\n";
    else
    {
    	int cnt=0;
    	for(int i=0;i<V;i++)
    	{
    		if(dist[i].f==m)
    		  cnt++;
		}
		cout<<m<<" "<<cnt<<"\n";
	}
}
int main() 
{
	int n,m,q,a,W=0;
	cin>>n>>m>>q;
	vector<vector<node>>adj(n);
	for(int i=0;i<m;i++)
	{
		node d;
		cin>>a;
		cin>>d.data>>d.wt;
	    W=max(W,d.wt);
		adj[a].pb(d);
		if(a!=d.data)
		  adj[d.data].pb({a,d.wt});
	}
	for(int i=0;i<q;i++)
	{
		cin>>a;
		farthestdist(a,adj,W,n);
	}
	return 0;
}
