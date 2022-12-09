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
    
    int solve(TreeNode* root , int maxVal , int minVal)
    {
        if(!root)
        {
            return abs(maxVal - minVal);
        }
        
        maxVal = max(maxVal , root->val);
        minVal = min(minVal , root->val);
        
        int l = solve(root->left , maxVal , minVal);
        int r = solve(root->right , maxVal , minVal);
        
        return max(l , r);
    }
    int maxAncestorDiff(TreeNode* root) {
        
        
        int res = solve(root , root->val , root->val);
        
        return res;
    }
};