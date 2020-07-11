class Solution 
{
public:
int memoization(int d, int f, int target) {
        vector<vector<int>> mem(d + 1, vector<int>(target + 1, -1));
        return solve(f, mem, d, target);
    }
    
    int solve(int f, vector<vector<int>>& mem, int d, int target) {
        if (d == 1) return target <= f ? 1 : 0;
        if (mem[d][target] >= 0) return mem[d][target];
        
        mem[d][target] = 0;
        for(int i = 1; i <= f && target - i > 0; ++i) {
            mem[d][target] = (mem[d][target] + solve(f, mem, d-1, target-i)) % 1000000007;
        }
        
        return mem[d][target];
    }
   int numRollsToTarget(int d, int f, int target) 
   {
        return memoization(d,f,target);
    }
};
