class Solution 
{
public:
vector<int> FindUnassignedLocation(vector<vector<char>>grid)  
{  
    for (int row = 0; row <9; row++)  
        for (int col = 0; col <9; col++)  
            if (grid[row][col] == '.')  
                return {row,col};  
    return {};  
}  
bool issafe(int i,int j,char elem,vector<vector<char>>&A)
{
    if(A[i][j]!='.')
          return true;
    for(int p=0;p<9;p++)
    {
        if(A[i][p]==elem)
           return false;
    }
    for(int p=0;p<9;p++)
    {
        if(A[p][j]==elem)
          return false;
    }
    int blockrow=(i-i%3),blockcol=(j-j%3);
    for(int p=blockrow;p<blockrow+3&&p<9;p++)
    {
        for(int q=blockcol;q<blockcol+3&&q<9;q++)
        {
            if(A[p][q]==elem)
               return false;
        }
    }
    return true;
}
bool recurse(vector<vector<char>>&A)
{
    vector<int>emptyloc=FindUnassignedLocation(A);
    if(emptyloc.size()==0)
          return true;
     int row=emptyloc[0],col=emptyloc[1];
    for(char i='1';i<='9';i++)
    {
        if(issafe(row,col,i,A))
        {
            A[row][col]=i;
            if(recurse(A))
                  return true;
            A[row][col]='.';
        }
    }
    return false;
}  

    void solveSudoku(vector<vector<char>>& board) 
    {
        recurse(board);
        return;
    }
};
