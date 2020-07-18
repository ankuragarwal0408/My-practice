class Solution {
public:
void csum(vector<int>arr,int i,int sum,int a,vector<int>r,set<vector<int>>&s)
{
    if(a>sum)
     return;
     if(a==sum)
     {
         s.insert(r);
         return;
     }  
    if(i<0||i>=arr.size())
      return;
  for(int j=i;i<arr.size();i++)
    {
         r.push_back(arr[i]);
        csum(arr,i+1,sum,a+arr[i],r,s);
        r.pop_back();
    }
    return;
}
vector<vector<int>> combinationSum2(vector<int>&A, int B) 
{
      vector<int>r;
    vector<vector<int>> res;
    sort(A.begin(),A.end());
    res.clear();
    set<vector<int>>s;
    csum(A,0,B,0,r,s);
    for(auto it=s.begin();it!=s.end();it++)
      res.push_back(*it);
    return res;
}
};
