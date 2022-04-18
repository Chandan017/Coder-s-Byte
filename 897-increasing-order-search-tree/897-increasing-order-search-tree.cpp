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
    TreeNode* curr ;
    
    void get(TreeNode* root)
    {
        if(root==NULL)
            return ;
        get(root->left);
        
        root->left = NULL;
        
        curr->right = root;
        curr = root;
        
        get(root->right);
        
        return ;
    }
    TreeNode* increasingBST(TreeNode* root) {
        
        TreeNode* ans = new TreeNode(0);
        curr = ans;
        
        get(root);
        
        return ans->right;
    }
};