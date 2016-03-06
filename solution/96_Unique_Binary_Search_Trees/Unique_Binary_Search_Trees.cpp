class Solution {
public:
    int numTrees(int n) {
        int dp[n + 1];
        memset(dp, 0, (n + 1) * sizeof(int));
        dp[0] = 1;
        
        for(int i = 1;i <= n;i++)
        {
            for(int j = 0;j * 2 < i;j++)
            {
                dp[i] += (2 * dp[j] * dp[i - j - 1]);
            }
    
            if(i % 2 == 1)
                dp[i] -= (dp[i / 2] * dp[i / 2]);
        }
        return dp[n];
    }
};