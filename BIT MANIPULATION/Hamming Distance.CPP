class Solution 
{
public:
    int hammingDistance(int x, int y) 
    {
       int a=1,cnt=0;
      while(x>0||y>0)
      {
          int s=x&a,v=y&a;
          x=(x/2);
          y=(y/2);
          if(s!=v)
              cnt++;
      }
        return cnt;
    }
};
