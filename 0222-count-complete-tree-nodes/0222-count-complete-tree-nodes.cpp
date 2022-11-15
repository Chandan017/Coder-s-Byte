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
    
    int getLeft(TreeNode* root)
    {
        int left = 0;
        
        while(root)
        {
            left++;
            root = root->left;
        }
        
        return left;
    }
    
    int getRight(TreeNode* root)
    {
        int right = 0;
        while(root)
        {
            right++;
            root = root->right;
        }
        
        return right;
    }
    
    
    int countNodes(TreeNode* root) {
        
        if(!root)
            return 0;
        
        int lh = getLeft(root);
        int rh = getRight(root);
        
        if(lh == rh)
        {
            return pow(2,lh)-1;
        }
        
        return  1 + countNodes(root->left) + countNodes(root->right);
        
    }
};