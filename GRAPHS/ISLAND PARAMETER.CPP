class Solution 
{
public:
    int dirx[4]={-1,1,0,0};
    int diry[4]={0,0,-1,1};
    int islandPerimeter(vector<vector<int>>& grid) 
    {
        set<pair<int,int>>vis;
        int m=grid.size(),n=grid[0].size();
        queue<pair<int,int>>q;
        int f=1;
        for(int i=0;i<m&&f==1;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==1)
                {
                    f=0;
                    q.push({i,j});
                    vis.insert({i,j});
                    break;
                }
            }
        }
        int peri=0;
        while(!q.empty())
        {
            int s=q.size();
            while(s--)
            {
                pair<int,int>p=q.front();
                q.pop();
                for(int k=0;k<4;k++)
                {
                    int x=p.first+dirx[k];
                    int y=p.second+diry[k];
                    if(x>=0&&x<m&&y>=0&&y<n&&grid[x][y]==1)
                    {
                        if(vis.find({x,y})==vis.end())
                        {
                            q.push({x,y});
                            vis.insert({x,y});
                        }
                    }
                    else
                        peri++;
                }
            }
        }
        return peri;
    }
};
