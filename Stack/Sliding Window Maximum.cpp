vector<int> Solution::slidingMaximum(const vector<int> &A, int B) 
{
    int n=A.size();
    int l=0,r=0,m=INT_MIN;
    vector<int>C;
    map<int,int,greater<int>>freq;
    while(r<n&&(r-l)<B)
    {
        freq[A[r]]++;
        m=max(m,A[r]);
        r++;
    }
    C.push_back(m);
    if(B>=n)
      return {m};
    while(r<n)
    {
        freq[A[l]]--;
        freq[A[r]]++;
        if(freq[A[l]]==0)
           freq.erase(A[l]);
        m=freq.begin()->first;
        C.push_back(m);
         l++;
         r++;
    }
    return C;
}
