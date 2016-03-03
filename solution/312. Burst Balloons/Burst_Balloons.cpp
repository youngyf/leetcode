class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();

        // n == 0
        if(n == 0)
            return 0;

        // 前后各插入一个1
        nums.insert(nums.begin(), 1);
        nums.push_back(1);

        // 二维数组
        // vector< vector<int> > dp(n, vector<int> (n));
        int* dp = new int[n * n];
        memset(dp, 0, n * n * sizeof(int));

        // init dp[i, i]
        for(int i = 0;i < n;i++)
        {
            // dp[i, i] = nums[i-1 + 1] * nums[i + 1] * nums[i+1 + 1]
            dp[i * n + i] = nums[i] * nums[i + 1] * nums[i + 2];
        }

        // dp
        for(int j = 0;j < n;j++) // j: 0 -> n-1
        {
            for(int i = j - 1;i >= 0; i--)  // i: j-1 -> 0
            {
                for(int k = i;k <= j;k++)  //k: i -> j
                {
                    // nums[i-1 + 1] * nums[k + 1] * nums[j+1 + 1]
                    int sum = nums[i] * nums[k + 1] * nums[j + 2];;
                    // dp[i, j] = max(dp[i, k-1] + dp[k+1, j] + nums[i-1] * nums[j+1] + k)
                    if(k > i)
                        sum += dp[i * n + k - 1];
                    if(k < j)
                        sum += dp[(k + 1) * n + j];

                    dp[i * n + j] = max(dp[i * n + j], sum);
                }
            }
        }

/*
        for(int j = 0;j < n;j++)
            for(int i = 0;i <= j;i++)
            {
                printf("dp[%d, %d] = %d\n", i, j, dp[i * n + j]);
            }
*/

        return dp[0 * n + n-1];
    }
};
