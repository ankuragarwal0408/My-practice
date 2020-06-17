//https://leetcode.com/explore/interview/card/top-interview-questions-hard/116/array-and-strings/831/
class Solution 
{
public:
    int dirx[8]={-1,-1,1,1,0,0,1,-1};
    int diry[8]={-1,1,-1,1,1,-1,0,0};
    void gameOfLife(vector<vector<int>>& board) 
    {
       int m=board.size(),n=board[0].size(),cnt=0;
       for(int i=0;i<m;i++)
       {
           for(int j=0;j<n;j++)
           {
               cnt=0;
               for(int k=0;k<8;k++)
               {
                   int x=dirx[k]+i,y=diry[k]+j;
                   if(x>=0&&x<m&&y>=0&&y<n)
                   {
                       if(abs(board[x][y])==1)
                           cnt++;
                   }
               }
               if(board[i][j]==0&&cnt==3)
                   board[i][j]=2;
              if(board[i][j]==1&&(cnt>3||cnt<2))
                   board[i][j]=-1;
           }
       }
        
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(board[i][j]<0)
                    board[i][j]=0;
                else if(board[i][j]>0)
                    board[i][j]=1;
            }
        }
    }
};
