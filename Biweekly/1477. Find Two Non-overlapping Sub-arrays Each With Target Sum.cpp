class Solution 
{
public:
    vector<int> help(vector<int>& v,int t)
	{
		int n=v.size();
		unordered_map<int,int> m;
		m[0]=-1;
		vector<int> ans(n,n+1);
		vector<int> prefix(n,0);
		for(int i=0;i<n;i++)
		{
			int l=n+1;
			prefix[i]=(i==0?0:prefix[i-1])+v[i];
			int req=prefix[i]-t;
			if(m.find(req)!=m.end())
			{
				l=i-m[req];

			}
			m[prefix[i]]=i;
			ans[i]=min(l,(i==0?l:ans[i-1]));

		}
		return ans;
	}
	int minSumOfLengths(vector<int>& arr, int target)
	{
		int n=arr.size();
		vector<int> rev(arr.rbegin(),arr.rend());
		vector<int> l=help(arr,target);
		vector<int> r=help(rev,target);
		reverse(r.begin(),r.end());
		int ans=INT_MAX;
		for(int i=0;i<n-1;i++)
		{
			ans=min(ans,l[i]+r[i+1]);
		}
		return ans<=n?ans:-1;
	}
};
