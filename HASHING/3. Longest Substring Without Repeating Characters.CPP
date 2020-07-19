int Solution::lengthOfLongestSubstring(string A) 
{
      int l=0,r=0,max_length=1;
        if(A.length()==0)
            return 0;
        unordered_map<char,int> ump;
        while(l<=r&&r<A.size())
        {
            if(ump.find(A[r])==ump.end())
            {
                ump[A[r]]=1;
                r++;
            }
            else
            {
                int cnt=0;
                cnt=ump.size();
                max_length=max(max_length,cnt);
                while(A[l]!=A[r]&&l<=r&&l<A.size())
                {
                    ump.erase(A[l]);
                    l++;
                }
                l++;
                r++;
            }
        }
        int c=ump.size();
       max_length=max(max_length,c);
        return max_length;
}
