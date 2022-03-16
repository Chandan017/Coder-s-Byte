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
        return (!root->left && !root->right);
    }
    bool check(TreeNode* root , int sum)
    {
        if(root==NULL)
            return false;
        
        if(root->val==sum && isLeaf(root))
            return true;
        
        bool l=check(root->left , sum-root->val);
        bool r=check(root->right , sum-root->val);
        
        return (l||r);
    }
    
    bool hasPathSum(TreeNode* root, int targetSum) {
        
        if(root==NULL)
            return false;
        
        bool ans=check(root , targetSum);
        
        return ans;
        
    }
};