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
    vector<int> inorder;
    
    void get(TreeNode* root)
    {
        if(root==NULL)
            return ;
        
        get(root->left);
        
        inorder.push_back(root->val);
        
        get(root->right);
        
        return ;
        
        
    }
    TreeNode* increasingBST(TreeNode* root) {
        
        if(root==NULL)
            return root;
        
        get(root);
        
        TreeNode* ans = new TreeNode(0);
        TreeNode* temp = ans;
        
        for(auto it:inorder)
        {
            temp->right = new TreeNode(it);
            temp = temp->right;
        }
        
        
        return ans->right;
        
    }
};