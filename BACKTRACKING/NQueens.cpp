vector<vector<string>>res;
bool issafe(int i,int j,vector<string>&board,int m)
{
    int p=i,q=j;
    // in the row
    for(int z=0;z<m;z++)
    {
            if(board[p][z]=='Q')
               return false;

    }
    // in the col
    for(int z=0;z<m;z++)
    {
       if(board[z][q]=='Q')
              return false;
    }
    // north east
    while(p>=0&&q<m)
    {
       
            if(board[p][q]=='Q')
              return false;
        
        p--,q++;
    }
    p=i,q=j;
    // north west
     while(p>=0&&q>=0)
    {
       
            if(board[p][q]=='Q')
              return false;
     
        p--,q--;
    }
     p=i,q=j;
     // south west
     while(p<m&&q<m)
    {
          if(board[p][q]=='Q')
              return false;
        
        p++,q++;
    }
     p=i,q=j;
     // south east
     while(p<m&&q>=0)
    {
        if(board[p][q]=='Q')
              return false;
        
        p++,q--;
    }
    return true;
}
void recurse(int A,vector<string>&temp,int row,int queens)
{
    if(row>=A)
      {
        if(queens==0)
          res.push_back(temp);
          return;
      }      
    for(int i=0;i<A;i++)
    {
        if(issafe(row,i,temp,A))
        {
            //cout<<row<<" "<<i<<"\n";
            temp[row][i]='Q';
            recurse(A,temp,row+1,queens-1);
            temp[row][i]='.';
        }  
         
    }
}
vector<vector<string> > Solution::solveNQueens(int A) 
{
  res.clear();
  vector<string>temp(A);
  for(int i=0;i<A;i++)
    temp[i]=string(A,'.');
   recurse(A,temp,0,A);
   return res;
}
