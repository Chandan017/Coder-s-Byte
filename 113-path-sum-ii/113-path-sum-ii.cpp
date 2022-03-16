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
    
    
    vector<vector<int>> ans;
    
    bool isLeaf(TreeNode* root)
    {
        return (!root->left && !root->right);
    }
    void get(TreeNode* root,vector<int> curr , int currSum , int targetSum)
    {
        if(root==NULL)
            return ;
        curr.push_back(root->val);
        currSum+=root->val;
        
        if(currSum==targetSum && isLeaf(root))
        {
            ans.push_back(curr);
            return ;
        }
        
        get(root->left , curr, currSum , targetSum);
        get(root->right , curr , currSum , targetSum);
        
        return ;
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        
        vector<int> curr;
        int currSum=0;
        
        get(root , curr , currSum , targetSum);
        
        return ans;
        
    }
};