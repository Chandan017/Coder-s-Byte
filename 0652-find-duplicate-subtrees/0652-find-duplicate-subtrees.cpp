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
    vector<TreeNode*> res;
    unordered_map<string,int> mpp;
    string serial(TreeNode* root)
    {
        if(!root)
            return "#";
        
        string l = serial(root->left);
        string r = serial(root->right);
        
        string curr = l + ',' + r + ',' + to_string(root->val);
        
        if(mpp[curr] == 1)
        {
            res.push_back(root);
        }
        
        mpp[curr]++;
        
        return curr;
    }
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        
        serial(root);
        
        return res;
    }
};