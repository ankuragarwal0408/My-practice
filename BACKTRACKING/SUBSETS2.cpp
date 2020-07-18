class Solution {
public:
    vector<vector<int>> s;
void sub(vector<int>nums,int i,vector<int> &su)
{
//	static vector<vector<int>> res;
	if(i>=nums.size())
	return;
	else
	{
		s.push_back(su);
	   for(int j=i+1;j<nums.size();j++)
	   {
	   	 su.push_back(nums[j]);
	     sub(nums,j,su);
	   	 su.pop_back();
	   }
	   	
	}
}
map<vector<int>,int> mp;
vector<vector<int>> subsetsWithDup(vector<int>& nums) 
    {
        vector<vector<int>> res;
       vector<int> g;
    sort(nums.begin(),nums.end());
	    res.push_back(g);
	    int m=nums.size();
	     for(int i=0;i<m;i++)
	    {
	     vector<int> su;
	     su.push_back(nums[i]);
	      s.clear();
	      sub(nums,i,su);
	      for(int j=0;j<s.size();j++)
	     {
	  	   vector<int> a;
	       for(int k=0;k<s[j].size();k++)
            a.push_back(s[j][k]);
        if(mp.find(a)==mp.end())
        {
            res.push_back(a);
            mp[a]++;
        }   
	     }	
	}
	return res;
    }
};
