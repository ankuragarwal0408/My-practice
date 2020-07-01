class Solution 
{
public:
    vector<bool> canMakePaliQueries(string s, vector<vector<int>>& queries) 
    {
        int n=queries.size();
        vector<vector<int>>alpha(s.length()+1,vector<int>(26,0));
        alpha[0][s[0]-'a']++;
        for(int i=1;i<=s.length();i++)
        {
            alpha[i][s[i-1]-'a']++;
            for(int j=0;j<26;j++)
               alpha[i][j]+=alpha[i-1][j];
        }
        vector<bool>ans;
        for(int i=0;i<n;i++)
        {
            int cntofodd=0;
            int l=queries[i][0],r=(queries[i][1]),k=queries[i][2];
                for(int j=0;j<26;j++)
               {
                    int h=alpha[r+1][j]-alpha[l][j];
                   if(h%2!=0)
                     cntofodd++;
                }     
            if(k>=(cntofodd/2))
              ans.push_back(true);
            else
                ans.push_back(false);
        }
        return ans;
    }
};
