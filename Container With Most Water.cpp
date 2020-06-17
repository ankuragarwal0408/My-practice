class Solution {
public:
    int maxArea(vector<int>& height) 
    {
     int m=height.size(),marea=INT_MIN;
      if(m==0||m==1)
          return 0;
     else if(m==2)
     {
        marea=max(marea,abs(min(height[0],height[1])));
        return marea;
     }
    else
    {
        int l=0,r=height.size()-1;
        while(l<r)
        {
            if(height[r]>=height[l])
            {
                marea=max(marea,abs(height[l]*(r-l)));
                l++;
            }   
            else if(height[r]<height[l])
            {
                marea=max(marea,abs(height[r]*(r-l)));
                r--;
              
            }   
        }
        return marea;
    }
    }
};
