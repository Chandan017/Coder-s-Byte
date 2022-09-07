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
  
    string build(TreeNode* root)
    {
        if(!root)
            return "";
        
        
        string res = "";
        res += to_string(root->val);
        
        bool hasLeft = false , hasRight = false;
        
        if(root->left)
            hasLeft = true;
        if(root->right)
            hasRight = true;
        
        if(hasLeft)
        {
            res += '(';
            
            res += build(root->left);
            res += ')';        
        }
        
        if(hasRight)
        {
            
            if(!hasLeft)
                res += "()";
            
            res += '(';
            res += build(root->right);
            res += ')';
            
        }
        
        
        return res;
       
       
    }
  
    string tree2str(TreeNode* root) {
        
        string ans = "";
        
        string res = build(root);
        
        return res;
        
    }
};