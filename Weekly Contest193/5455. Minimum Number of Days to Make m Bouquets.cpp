bool check(vector<int>& v, int m, int k,int mid)
	{
		int tot=0,c=0;
		for(int i=0;i<v.size();i++)
		{
			if(v[i]<=mid)
			{
				c++;
				if(c==k)
				{
					tot++;// because we want adjacent flowers to pick up
					c=0;// total take cares of the number of bouqets
				}
			}
			else c=0;// we want adjacent flowers therefore we need to continously update the c which keep the count
      // no of adjacent flowers 
		}
		if(tot>=m)return true;
		return false;
	}
	int minDays(vector<int>& bloomDay, int m, int k)
	{
		int s=0,e=INT_MAX-1;
		int ans=-1;
		while(s<=e)
		{
			int mid=s+(e-s)/2;
			if(check(bloomDay,m,k,mid))
			{
				ans=mid;// we are trying to find minimum days to make this therefore trying to decrease the mid
				e=mid-1;
			}
			else
			{
				s=mid+1;// we didn't find it means we need more days to accomplish the task 
			}
		}
		return ans;
	}
