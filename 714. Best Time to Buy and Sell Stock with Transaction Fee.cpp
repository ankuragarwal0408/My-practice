// 2nd solution
class Solution {
    // https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/discuss/108867
    // Normally we DP index dp[i] = dp[i - 1] + ....
    // But there is another way to DP the state, e.g. this question
    public int maxProfit(int[] prices, int fee) {
        // two states:
        // "hold" state: represent the max profit when we hold a stock at time i - 1.
        // "empty" state: represent the max profit when we do not hold a stock at time i - 1.
        // initialization:
        // for "hold" state, we hold one stock, so the profit is -prices[0]
        // for "empty" state, we do not hold stock, so the profit is 0
        int hold = -prices[0], empty = 0;
        for (int i = 1; i < prices.length; i++) {
            // on current time i
            // the max profit of hold state is either we still hold the stock we hold at the i-1 time(hold)
            // or we buy new stock(empty - prices[i])
            hold = Math.max(hold, empty - prices[i]);
            // the max profit of enpty state is eighter we still keep our hand empty(empty)
            // or we sell the stock we already hold(hold + prices[i] - fee)
            empty = Math.max(empty, hold + prices[i] - fee);
        }
        // return must be empty, because selling is better than holding one stock that has not been sold
        return empty;
    }
}

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
