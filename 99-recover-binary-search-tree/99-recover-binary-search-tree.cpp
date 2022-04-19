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
  
    TreeNode *first , *second , *prev = new TreeNode(INT_MIN);
    void get(TreeNode* root)
    {
        if(root==NULL)
            return ;
        get(root->left);
        
        if(first == NULL && prev->val > root->val)
        {
            first = prev;
        }
        
        if(first != NULL && prev->val > root->val)
        {
            second = root;
        }
        
        prev= root;
        
        get(root->right);
        
        return ;
    }
    
    
    void recoverTree(TreeNode* root) {
        
        get(root);
        
        
        swap(first->val , second->val);
        
       
        return ;
    }
};