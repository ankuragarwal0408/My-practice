class Solution 
{
public:
    string convert(string s, int numRows) 
    {
        int n=s.length();
        if(numRows==1)
            return s;
        vector<vector<char>>board(numRows,vector<char>(n,'#'));
        int i=0,j=0,dir=0;
        while(i>=0&&i<numRows&&j<n)
        {
            board[i][j]=s[j];
            if((i+1)>=numRows)
             dir=1;
            else if((i-1)<0)
              dir=0;
            if(dir==0)
                i++;
            else
                i--;
            j++;
        }
        string ans="";
        for(int i=0;i<numRows;i++)
        {
            for(int j=0;j<n;j++)
            {
               if(board[i][j]!='#')
                   ans+=board[i][j];
            }
        }
        return ans;
    }
};
