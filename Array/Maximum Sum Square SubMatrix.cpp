int Solution::solve(vector<vector<int> > &A, int B) 
{
    int m=A.size(),n=A[0].size();
    vector<vector<int>>dp(m,vector<int>(n,0));
    dp[0][0]=A[0][0];
    for(int i=1;i<n;i++)
      dp[0][i]=A[0][i]+dp[0][i-1];
    for(int i=1;i<m;i++)
      dp[i][0]=A[i][0]+dp[i-1][0];
     
     for(int i=1;i<m;i++)
     {
         for(int j=1;j<n;j++)
         {
             dp[i][j]=A[i][j]+dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1];
         }
     }

     int ans=INT_MIN;
     for(int i=B-1;i<m;i++)
     {
         for(int j=B-1;j<n;j++)
         {
             int t=dp[i][j];
             if((i-B)>=0)
               t-=dp[i-B][j];
             if((j-B)>=0)
                t-=dp[i][j-B];
             if((i-B)>=0&&(j-B>=0))
                t+=dp[i-B][j-B];
            ans=max(ans,t);
         }
     }
     return ans;
}
