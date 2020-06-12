int trap(vector<int>& height) 
    {
        int n=height.size();
        if(n==0)
            return 0;
        vector<int>maxL(n,0),maxr(n,0);
        maxL[0]=height[0];
        for(int i=1;i<n;i++)
         maxL[i]=max(maxL[i-1],height[i]);
        maxr[n-1]=height[n-1];
        for(int i=n-2;i>=0;i--)
         maxr[i]=max(maxr[i+1],height[i]);
        int ans=0;
        for(int i=0;i<n;i++)
        {
            ans+=(min(maxr[i],maxL[i])-height[i]);
        }
        return ans;
    }
