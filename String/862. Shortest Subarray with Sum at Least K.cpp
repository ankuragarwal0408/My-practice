class Solution 
{
public:
    int shortestSubarray(vector<int>& A, int K) 
    {
       int n=A.size();
       
       vector<int>prefix(n+1,0);
       
       for(int i=0;i<n;i++)
           prefix[i+1]=A[i]+prefix[i];
        
       deque<int>q;
        int minlen=INT_MAX;
       for(int i=0;i<n+1;i++)
       {
          while(!q.empty()&&(prefix[i]-prefix[q.front()])>=K)
          {
              minlen=min(minlen,i-q.front());
              q.pop_front();
          }
          while(!q.empty()&&(prefix[i]-prefix[q.back()])<=0)  q.pop_back();
           
          q.push_back(i);
       }
      if(minlen==INT_MAX)
          return -1;
        
        return minlen;
    }
};
