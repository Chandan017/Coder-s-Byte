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
    vector<vector<int>> res;
    
    bool isLeaf(TreeNode* root)
    {
        return (!root->left && !root->right);
    }
    
    void collect(TreeNode* &root , vector<int> &temp)
    {
        if(!root)
            return ;
        
        if(isLeaf(root))
        {
            temp.push_back(root->val);
            root = NULL;
            return ;
        }
        
        if(root->left)
        {
            if(isLeaf(root->left))
            {
                temp.push_back(root->left->val);
                root->left = NULL;
            }
            else
                collect(root->left , temp);
        }
        
        if(root->right)
        {
            if(isLeaf(root->right))
            {
                temp.push_back(root->right->val);
                root->right = NULL;
            }
            else
                collect(root->right , temp);
        }
        return ;
    }
    vector<vector<int>> findLeaves(TreeNode* root) {
        
        
        while(root)
        {
            vector<int> temp;
            
            collect(root , temp);
            
            res.push_back(temp);
        }
        
        return res;
        
        
        
    }
};