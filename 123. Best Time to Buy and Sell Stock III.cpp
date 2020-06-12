class Solution 
{
public:
    int maxProfit(vector<int>& prices) 
    {
       int n=prices.size();
        if(n==0)
            return 0;
       int dp[3][n];
        for(int i=0;i<n;i++)
            dp[0][i]=0;
        for(int i=0;i<=2;i++)
            dp[i][0]=0;
        //O(kN) solution 
        for(int i=1;i<=2;i++)
        {
            int m=INT_MIN;
            for(int j=1;j<n;j++)
            {
                m=max(m,-prices[j-1]+dp[i-1][j-1]);// it means
                // that buying at index j-1 and considering at that point what maximum profit
                // upto k-1the transaction I have achieved 
                // below line means that now if I sell it at this 
                // index then prices[j]+m will be the profit
                // if i don't do any transaction here then simply previous
                // column with same number of transactions will
                // be considered
                
                dp[i][j]=max(dp[i][j-1],prices[j]+m);
            }
        }
        
        return dp[2][n-1];
    }
};
