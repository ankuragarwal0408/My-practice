#include <bits/stdc++.h>
using namespace std;
bool comp(pair<int,int>&p,pair<int,int>&q)
{
    if(p.second<=q.second)
      return 1;
    else
      return 0;
}
int main() 
{
	int t,n;
	cin>>t;
	while(t--)
	{
	    cin>>n;
	    vector<int>v(n,0);
	    
	    for(int i=0;i<n;i++)
	      cin>>v[i];
	      int b=0;
	    vector<pair<int,int>>a(n,{0,0});
	    for(int i=0;i<n;i++)
	    {
	        cin>>b;
	        a[i]={v[i],b};
	    }
	    int cnt=1;
	    sort(a.begin(),a.end(),comp);
	    pair<int,int>last=a[0];
	    for(int i=1;i<n;i++)
	    {
	        if(a[i].first>=last.second)
	        {
	        //	 cout<<a[i].first<<" "<<a[i].second<<"\n";
	            last=a[i];
	            cnt++;
	        }
	    }
	   
	    cout<<cnt<<"\n";
	}
	return 0;
}
