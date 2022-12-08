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
    
    vector<int> getLeaf(TreeNode* root)
    {
        vector<int> res;
        
        deque<TreeNode*> q;
        q.push_back(root);
        
        while(q.size())
        {
            TreeNode* curr = q.back();
            q.pop_back();
            
            if(!curr->left && !curr->right)
            {
                res.push_back(curr->val);
            }
            
            if(curr->left)
                q.push_back(curr->left);
            if(curr->right)
                q.push_back(curr->right);
        }
        
        return res;
        
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        
        vector<int> leaf1 = getLeaf(root1);
        vector<int> leaf2 = getLeaf(root2);
        
    
        if(leaf1 == leaf2)
            return true;
        
        return false;
        
        
    }
};