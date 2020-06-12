class Solution 
{
public:
    map<pair<int,int>,int>mp;
    int recurse(vector<int>prices,int i,int n,int havestock)
    {
        if(i>=n)
            return 0;
        int ans=0;
        if(mp.find({i,havestock})!=mp.end())
            return mp[{i,havestock}];
        if(havestock==1)
            ans+=max(prices[i]+recurse(prices,i+2,n,0),recurse(prices,i+1,n,havestock));
            else
            ans+=max(-prices[i]+recurse(prices,i+1,n,1),recurse(prices,i+1,n,havestock));
        mp[{i,havestock}]=ans;
        return ans;
    }
    int maxProfit(vector<int>& prices) 
    {
      int n=prices.size();
       mp.clear();
        return recurse(prices,0,n,0);
    }
};
