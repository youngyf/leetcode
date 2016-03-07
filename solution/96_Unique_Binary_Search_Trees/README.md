枚举数组中的每个数i，把它们当作root.

root的左子树由 1~i-1 这i-1的数构成;右子树由i+1~n这n-i-1个数构成.左右子树可以递归的构建.

设dp[n]表示n个数构成Unique Binary Search Trees的数目。由递推关系式:
dp[n] = dp[0] \* dp[n-1] + dp[1] \* dp[n-2] + ... + dp[n-1] \* dp[0]

初始化:
dp[0] = dp[1] = 0 