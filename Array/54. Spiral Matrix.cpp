class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& A) {
         vector<int>ans;
        int m=A.size();
        if(m==0)
            return ans;
        int n=A[0].size();
   
        
    int t=0,b=m-1,l=0,r=n-1,dir=0;
    while(t<=b&&l<=r)
    {
        if(dir==0)
        {
            for(int i=l;i<=r;i++)
               ans.push_back(A[t][i]);
             dir=1;
             t++; 
        }
        else if(dir==1)
        {
            for(int i=t;i<=b;i++)
            {
                ans.push_back(A[i][r]);
            }
            dir=2;
            r--;
        }
        else if(dir==2)
        {
            for(int i=r;i>=l;i--)
              ans.push_back(A[b][i]);
             b--;
             dir=3;
        }
        else if(dir==3)
        {
            for(int i=b;i>=t;i--)
              ans.push_back(A[i][l]);
            l++;
            dir=0;
        }
    }
    return ans;
    }
};
