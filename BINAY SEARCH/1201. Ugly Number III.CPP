class Solution 
{
public:
    long  lcm(long a,long b)
    {
        return  (a*b)/__gcd(a,b);
    }
    int nthUglyNumber(int n, int aa, int bb, int cc) 
    {
    
        long l=0,r=INT_MAX;
        long o=0;
        long a=aa,b=bb,c=cc;
        while(l<=r)
        {
            long mid=(l+((r-l)/2));
            o=(mid/a)+(mid/b)+(mid/c)-(mid/lcm(a,b))-(mid/lcm(b,c))-(mid/lcm(a,c))+(mid/(lcm(a,lcm(b,c))));
            if(o<n)
                 l=mid+1;
            else
                r=mid-1;
        }
        return (int)l;
    }
};
