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
    
    bool helper(TreeNode* root , TreeNode* mini , TreeNode* maxi)
    {
        if(!root)
            return true;
        if((mini && root->val <= mini->val) || (maxi && root->val >= maxi->val))
            return false;

        bool l = helper(root->left , mini , root);
        bool r = helper(root->right , root , maxi);

        return (l&&r);
    }
    
    
    bool isValidBST(TreeNode* root) {
        
        
        return helper(root , NULL , NULL);
        
    }
};