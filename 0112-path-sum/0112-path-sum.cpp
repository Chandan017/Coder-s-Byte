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
    bool isLeaf(TreeNode* root)
    {
        return (!root->right && !root->left);
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        
        if(!root)
            return false;
        
        targetSum -= root->val;
        
        if(isLeaf(root) && targetSum == 0)
            return true;
        
        bool l = hasPathSum(root->left , targetSum);
        bool r = hasPathSum(root->right , targetSum);
        
        
        
        return (l||r);
        
    }
};