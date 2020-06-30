class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        
        int n=arr.size();
        unordered_map<int,int>m;
        int ans=0;
        for(auto i:arr){
            
            m[i]=1+m[i-difference];
            
            ans=max(ans,m[i]);
        }
       // for(auto i:m)cout<<i.second;
        
        return ans;
    }
};
