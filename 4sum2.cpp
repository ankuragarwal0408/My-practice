class Solution 
{
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) 
    {
        int a=A.size(),b=B.size(),c=C.size(),d=D.size();
        unordered_map<int,int>map1,map2;
        for(int i=0;i<a;i++)
        {
            for(int j=0;j<b;j++)
            {
                map1[A[i]+B[j]]++;
            }
        }
        for(int i=0;i<c;i++)
        {
            for(int j=0;j<d;j++)
            {
                map2[-(C[i]+D[j])]++;
            }
        }
        int cnt=0;
        for(auto it=map1.begin();it!=map1.end();it++)
        {
            int h=it->first;
            if(map2.find(h)!=map2.end())
            {
                auto iy=map2.find(h);
                cnt+=(it->second*iy->second);
            }
        }
        return cnt;
    }
};
