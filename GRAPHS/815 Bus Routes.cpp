class Solution 
{
public:
    int numBusesToDestination(vector<vector<int>>& routes, int S, int T) 
    {
       unordered_map<int,vector<int>>mp;
       int m=routes.size();
       int busstop=-1;
       for(int i=0;i<routes.size();i++)
       {
           mp[busstop]=routes[i];
           for(int j=0;j<routes[i].size();j++)
             mp[routes[i][j]].push_back(busstop);
            busstop--;
       }
        queue<pair<int,int>>q;
        unordered_set<int>vis;
        vis.insert(S);
        q.push({S,0});
        int ans=-1;
        while(!q.empty())
        {
            int s=q.size();
            while(s--)
            {
                pair<int,int>p=q.front();
                q.pop();
                int i=p.first,j=p.second;
                if(i==T)
                      return j;
                for(int z=0;z<mp[i].size();z++)
                {
                    if(mp[i][z]>0&&vis.find(mp[i][z])==vis.end())
                    {
                        vis.insert(mp[i][z]);
                        q.push({mp[i][z],j+1});
                    }
                    else if(vis.find(mp[i][z])==vis.end()&&mp[i][z]<0)
                    {
                        vis.insert(mp[i][z]);
                        q.push({mp[i][z],j});
                    }
                        
                }
            }
        }
        vector<int> busstops=mp[S];
        for(int i=0;i<busstops.size();i++)
        {
            int e=abs(busstops[i])-1;
            for(int j=0;j<routes[e].size();j++){
                if(routes[e][j]==T)
                      return 1;
            }
        }
        return ans;
    }
};
