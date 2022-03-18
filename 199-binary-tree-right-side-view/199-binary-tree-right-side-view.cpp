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
    
    vector<int> ans;
    
    void get(TreeNode* root  , int level)
    {
        if(root==NULL)
            return ;
        
        if(ans.size()==level)
            ans.push_back(root->val);
        
        get(root->right , level+1);
        get(root->left , level+1);
        
        return;
    }
    vector<int> rightSideView(TreeNode* root) {
        
        int level=0;
        get(root,level);
        
        return ans;
        
    }
};