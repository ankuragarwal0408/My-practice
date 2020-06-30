class Solution 
{
public:
    int equalSubstring(string s, string t, int maxCost) 
    {
       int m=s.length();//,n=t.length();
       int l=0,r=0,currtemp=0,maxlen=0;
        while(l<=r&&r<m)
        {  
            currtemp+=(abs(t[r]-s[r]));
            if(currtemp<=maxCost)
            {
                maxlen=max(r-l+1,maxlen);
            }else if(currtemp>maxCost)
            {
               currtemp-=abs(t[l]-s[l]);
               l++;
            }
            r++;
        }
        return maxlen;
    }
};
