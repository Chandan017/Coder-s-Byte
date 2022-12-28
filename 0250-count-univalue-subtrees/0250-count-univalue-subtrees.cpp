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
    
    bool check(TreeNode* root , int value)
    {
        if(!root)
            return true;
        
        if(root->val != value)
            return false;
        
        bool l = check(root->left , value);
        bool r = check(root->right , value);
        
        return (l&&r);
    }
    
    int countUnivalSubtrees(TreeNode* root) {
        
        if(!root)
            return 0;
        
        int cnt = countUnivalSubtrees(root->left);
        cnt += countUnivalSubtrees(root->right);
        
        if(check(root , root->val))
            cnt++;
        
        return cnt;
    }
};