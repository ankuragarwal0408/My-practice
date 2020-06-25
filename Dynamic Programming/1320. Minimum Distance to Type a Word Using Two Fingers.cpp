class Solution 
{
public:
    unordered_map<char,pair<int,int>>mp;
    int dp[301][28][28];
    int calc(int f1,int newpos)
    {
        if(f1==27)
            return 0;
        char y=f1+'A';
        pair<int,int>p=mp[y],q=mp[newpos];
        return (abs(p.second-q.second)+abs(p.first-q.first));
    }
    int recurse(int i,int f1,int f2,string word)
    {
       if(i>=word.length())
            return 0;
        if(dp[i][f1][f2]!=-1)
            return dp[i][f1][f2];  
        int choice1=calc(f1,word[i])+recurse(i+1,word[i]-'A',f2,word);
        int choice2=calc(f2,word[i])+recurse(i+1,f1,word[i]-'A',word);
        return dp[i][f1][f2]=min(choice1,choice2);
    }
    int minimumDistance(string word) 
    {
        int n=word.length();
        char st='A';
        int i=0;
        mp.clear();
        memset(dp,-1,sizeof(dp));
       while(st<='Z')
        {
            mp[st]={i/6,i%6};
            st++,i++;
        }
        return recurse(0,27,27,word);
    }
};
