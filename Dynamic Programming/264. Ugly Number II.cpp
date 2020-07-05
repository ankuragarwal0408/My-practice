class Solution 
{
public:
    int nthUglyNumber(int n) 
    {
        if(n==1)
             return 1;
        int ugly[n];
        ugly[0]=1;
        int id1=0,id2=0,id3=0;
        int cnt=1;
        while(cnt<n)
        {
          int next2=ugly[id1]*2;
          int next3=ugly[id2]*3;
          int next5=ugly[id3]*5;
            int next=min({next2,next3,next5});
            if(next==next2)
                id1++;
            if(next==next3)
                id2++;
            if(next==next5)
                id3++;
            ugly[cnt++]=next;
        }
        return ugly[n-1];
            
    }
};
