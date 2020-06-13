#define mod 1000000007
class Solution 
{
public:
    int dp[100001];
    int dfs(string &s,int i,int k)
    {
        if(i>=s.length())
            return 1;
        if(dp[i]!=-1)
            return dp[i];
        if(s[i]=='0')
            return 0;
        long long  num=0;
        int ans=0;
       for(int j=i;j<s.length();j++)
       {
           num=num*10+(s[j]-'0');
           if(num>k)
               break;
           ans+=(dfs(s,j+1,k));
           ans%=mod;
       }
        return dp[i]=ans;
    }
    int numberOfArrays(string s, int k) 
    {
       int n=s.length();
       for(int i=0;i<=n;i++)
           dp[i]=-1;
      return dfs(s,0,k);
    }
};
