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
    
    void getAllPaths(TreeNode* root , vector<int> &currPath , int targetSum)
    {
        if(!root)
            return ;
        
        targetSum -= root->val;
        currPath.push_back(root->val);
        
        if(isLeaf(root) && targetSum==0)
        {
            res.push_back(currPath);
            currPath.pop_back();
            return ;
        }
        
        getAllPaths(root->left , currPath , targetSum);
        getAllPaths(root->right , currPath , targetSum);
        
        currPath.pop_back();
        return ;
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        
        
        vector<int> currPath;
        
        getAllPaths(root , currPath , targetSum);
        
        return res;
    }
};