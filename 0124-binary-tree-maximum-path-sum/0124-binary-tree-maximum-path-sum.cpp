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

    long solve(TreeNode* root)
    {
        if(!root)
            return INT_MIN;
        
        long l = solve(root->left);
        long r = solve(root->right);
        
        if(max(l,r) < 0)
        {
            return root->val;
        }
        
        long res = max(l , r);
        
        return (res + root->val);
        
    }
    int maxPathSum(TreeNode* root) {
        
        if(!root)
            return INT_MIN;
        
        int res = root->val;
        if(root->left)
        {
            long curr= solve(root->left);
            if(curr > 0)
                res += curr;
        }
        if(root->right)
        {
            int curr = solve(root->right);
            if(curr > 0)
                res += curr;
        }
    
        
        int l = maxPathSum(root->left);
        int r = maxPathSum(root->right);
        
        
        return max({res , l , r});
    }
};