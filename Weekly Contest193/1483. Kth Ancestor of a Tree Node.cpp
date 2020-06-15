class TreeAncestor 
{
public:
    
    int dp[500009][29];
    int height; 
    
    void calculateSparse(int u, int v) 
    {  
        dp[v][0] = u; 
        for (int i = 1; i <= height; i++)  
        { 
            dp[v][i] = dp[dp[v][i - 1]][i - 1]; 
            if (dp[v][i] == -1) 
                return; 
        } 
    } 

    TreeAncestor(int n, vector<int>& parent) 
    {
        memset(dp, -1, sizeof(dp));
        this->height = (int)ceil(log2(n));
        
        for(int i = 1; i < parent.size(); i++) 
        {
            calculateSparse(parent[i], i);
        }
    }
    
    int getKthAncestor(int node, int k) 
    {
        
        for (int i = 0; i <= height; i++) 
        { 
            if (k & (1 << i))
            { 
                node = dp[node][i]; 
                if (node == -1) 
                    return -1; 
            } 
        } 
        return node; 
    }
};
