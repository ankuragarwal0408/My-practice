class Solution 
{
public:
     bool isGoodArray(vector<int>& A) 
     {
        int res = A[0];
        for (int a: A)
            res = __gcd(res, a);
        return res == 1;
    }
};
