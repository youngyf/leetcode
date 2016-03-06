class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
        // dp[0] = NULL
        vector<vector<TreeNode*> > dp(n + 1);
        // empty
        if(n == 0)
            return dp[0];
        // intial dp[0]
        dp[0].push_back(NULL);
        // initial dp[1]
        dp[1].push_back(new TreeNode(1));
        
        
        for(int i = 2;i <= n;i++)
        {
            for(int j = 0;j < i;j++)
            {
                for(int m = 0;m < dp[j].size();m++)
                {
                    TreeNode* left = dp[j][m];
                    // pointer for left child
                    TreeNode* l = this->copyTree(left, 0);
                    for(int q = 0;q < dp[i - j - 1].size();q++)
                    {
                        TreeNode* right = dp[i - j - 1][q];
                        // pointer for right child
                        TreeNode* r = copyTree(right, j + 1);
                        // root pointer
                        TreeNode* root = new TreeNode(j + 1);
                        root->left = l;
                        root->right = r;

                        dp[i].push_back(root);
                    }
                }
            }
        }

        return dp[n];
    }

    TreeNode* copyTree(TreeNode* pt, int dis) {
        if(pt == NULL)
            return NULL;

        TreeNode* root = new TreeNode(pt->val + dis);

        if(pt->left)
            root->left = copyTree(pt->left, dis);
        if(pt->right)
            root->right = copyTree(pt->right, dis);

        return root;
    }
};