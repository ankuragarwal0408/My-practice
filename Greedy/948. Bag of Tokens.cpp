class Solution 
{
public:
    int bagOfTokensScore(vector<int>& tokens, int P) 
    {
       int n=tokens.size();
        int l=0,r=n-1,points=0;
        sort(tokens.begin(),tokens.end());
        while(l<n)
        {
            while(l<n&&P>=tokens[l])
            {
                points++;
                P-=tokens[l];
                l++;
            }
            if(l>=r)
                  break;
            if(points==0)
                break;
             P+=tokens[r];
             points--;
             r--;
        }
        return points;
    }
};
