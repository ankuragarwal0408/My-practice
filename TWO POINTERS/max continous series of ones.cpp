vector<int> Solution::maxone(vector<int> &A, int B) 
{
    int n=A.size();
    int l=0,r=0;
    int maxlen=INT_MIN;
    int left=INT_MIN,right=INT_MAX;
    while(r<n)
    {
        if(A[r]==1)
           r++;
        else if(A[r]==0&&B>0)
        {
            r++;
            B--;
        }
        else if(A[r]==0&&B==0)
        {
              if(maxlen<(r-l))
              {
                  maxlen=r-l;
                  left=l,right=r;
              }
              while(l<n&&A[l]!=0)
                l++;
           l++;
           B++;
        }
    }
     if(maxlen<(r-l))
    {
        maxlen=r-l;
        left=l,right=r;
    }
    if(left==INT_MIN||right==INT_MAX)
    {
        left=l,right=r;
    }
    vector<int>ans;
    for(int i=left;i<right;i++)
      ans.push_back(i);
    return ans;
}
