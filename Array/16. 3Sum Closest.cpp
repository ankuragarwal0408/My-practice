class Solution 
{
public:
    int threeSumClosest(vector<int>& nums, int target) 
    {
       int n=nums.size();
     //   sort(nums.begin(),nums.end());
       unordered_map<int,pair<int,int>>mp;
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
              mp[nums[i]+nums[j]]={i,j};
        }
        int mindiff=INT_MAX;
        int ans=0;
        for(int i=0;i<n;i++)
        {
            for(auto it=mp.begin();it!=mp.end();it++)
            {
               if(i!=(it->second.first)&&i!=it->second.second)
               {
                   int a=it->first+nums[i];
                   if(mindiff>abs(a-target))
                   {
                       mindiff=abs(a-target);
                       ans=a;
                   }
               }
            }
        }
        return ans;
    }
};
