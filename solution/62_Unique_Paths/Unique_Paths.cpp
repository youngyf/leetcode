class Solution {
public:
    int uniquePaths(int m, int n) {
        int dp[n];
        memset(dp, 0, n * sizeof(int));
        dp[0] = 1;
        
        for(int i = 0;i < m;i++)
        {
            for(int j = 0;j < n;j++)
            {
                if(j > 0)
                    dp[j] += dp[j - 1];
            }
            
        }
        
        return dp[n-1];
    }
};