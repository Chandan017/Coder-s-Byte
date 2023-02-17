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
    
    int mini = INT_MAX;
    TreeNode* pre;
    void solve(TreeNode* root)
    {
        if(!root)
            return ;
        
        solve(root->left);
        
        if(pre)
        {
            mini = min(mini , abs(root->val - pre->val));
        }
        
        pre = root;
        solve(root->right);
        
        return ;
    }
    int minDiffInBST(TreeNode* root) {
        
        
        solve(root);
        return mini;
    }
};