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
    int cnt = 0;
    
    void solve(TreeNode* root)
    {
        if(!root)
            return ;
        cnt++;
        solve(root->left);
        solve(root->right);
        return ;
    }
    int countNodes(TreeNode* root) {
        
        if(!root)
            return 0;
        
        
        solve(root);
        
        return cnt;
        
    }
};