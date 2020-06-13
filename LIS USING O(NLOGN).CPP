class Solution 
{
public:
    int lcs(vector<int>nums)
    {
       vector<int>seq;
        seq.push_back(nums[0]);
        for(int i=1;i<nums.size();i++)
        {
            if(seq.back()<nums[i])
                seq.push_back(nums[i]);
            else
            {
                int ind=lower_bound(seq.begin(),seq.end(),nums[i])-seq.begin();
                seq[ind]=nums[i];
            }
        }
        return seq.size();
    }
    int lengthOfLIS(vector<int>& nums) 
    {
      if(nums.size()==0)
           return 0;
        return lcs(nums);
    }
};
