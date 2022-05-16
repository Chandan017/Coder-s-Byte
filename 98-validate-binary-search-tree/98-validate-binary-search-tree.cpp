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
    
    bool check(TreeNode* root , TreeNode* minVal , TreeNode* maxVal)
    {
        if(root==NULL)
            return true;
        
        if((minVal != NULL && root->val <= minVal->val) || (maxVal != NULL && root->val >= maxVal->val))
            return false;
        
        bool leftCheck = check(root->left , minVal , root);
        bool rightCheck = check(root->right , root , maxVal);
        
        return (leftCheck && rightCheck);
    }
    
    bool isValidBST(TreeNode* root) {
        
        if(root==NULL)
            return true;
        
        
        bool ans = check(root , NULL , NULL);
        
        return ans;
        
    }
};