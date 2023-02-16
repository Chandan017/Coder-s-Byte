/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    map<TreeNode*,int> dp;
    int solve(TreeNode* root)
    {
        if(!root)
            return 0;
        
        if(dp.find(root) != dp.end())
            return dp[root];
        
        int take = root->val;
        if(root->left)
            take += solve(root->left->left) + solve(root->left->right);
        
        if(root->right)
            take += solve(root->right->left) + solve(root->right->right);
        
        int notTake = solve(root->left) + solve(root->right);
        
        dp[root] = max(take , notTake);
        
        return dp[root];
    }
    int rob(TreeNode* root) {
        
        int res = solve(root);
        
        return res;
    }
};