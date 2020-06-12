class Solution 
{
public:
       int dp[50001][2];
    int maxselling(vector<int>&prices,int i,int share,int fee )
    {
        if(i>=prices.size())
            return 0;
        int ans=0;
        if(dp[i][share]!=-1)
            return dp[i][share];
        if(share)// share h mere paas 
            ans+=max(prices[i]-fee+maxselling(prices,i+1,!share,fee),maxselling(prices,i+1,share,fee));
        else
            ans+=max(-prices[i]+maxselling(prices,i+1,!share,fee),maxselling(prices,i+1,share,fee));
        return dp[i][share]=ans;  
    }
    int maxProfit(vector<int>& prices, int fee) 
    {
        int n=prices.size();
        for(int i=0;i<50001;i++)
        {
            dp[i][0]=-1,dp[i][1]=-1;
        }
        return maxselling(prices,0,0,fee);
    }
};
