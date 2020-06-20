class Solution 
{
public:
    vector<string> topKFrequent(vector<string>& words, int k) 
    {
       int n=words.size();
       map<string,int>mp;
        for(int i=0;i<n;i++)
            mp[words[i]]++;
        map<int,vector<string>,greater<int>>mp2;
        for(auto it=mp.begin();it!=mp.end();it++)
        {
            mp2[it->second].push_back(it->first);
        }
        vector<string>ans;
        for(auto it=mp2.begin();it!=mp2.end()&&k>0;it++)
        {
            for(int i=0;i<it->second.size()&&k>0;i++)
            {
                ans.push_back(it->second[i]);
                k--;
            }
        }
        return ans;
    }
};
