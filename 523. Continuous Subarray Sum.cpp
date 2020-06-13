class Solution 
{
public:
    bool checkSubarraySum(vector<int>& nums, int k) 
    {
          int n=nums.size();
        if(n==0&&k==0)
            return false;
       vector<int>prefix(n,0);
        prefix[0]=nums[0];
        for(int i=1;i<n;i++)
        {
            prefix[i]=prefix[i-1]+nums[i];
        }
        
        if(k==0&&n==1&&prefix[0]==0)
            return false;
        int l=0,r=2;
        for(int i=1;i<n;i++)
        {
            if(k!=0&&prefix[i]%k==0)
                return true;
            if(k==0&&prefix[i]==0)
                return true;
        }
        while(l<=r&&r<n)
        {
            while(r<n)
            {
                if(k!=0&&(prefix[r]-prefix[l])%k==0)
                    return true;
                if(k==0&&(prefix[r]-prefix[l])==0)
                      return true;
                r++;
            }
            l++;
            r=l+2;
        }
        return false;
    }
};
