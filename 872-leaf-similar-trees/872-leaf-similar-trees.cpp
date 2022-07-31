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
    
    void getLeafs(TreeNode* root , vector<int> &res)
    {
        if(!root)
            return ;
        
        if(!root->left && !root->right)
        {
            res.push_back(root->val);
            return ;
        }
        
        getLeafs(root->left , res);
        getLeafs(root->right , res);
        
        return ;
    }
    
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        
        vector<int> leaf1 , leaf2;
        
        getLeafs(root1 , leaf1);
        getLeafs(root2 , leaf2);
        
        int n1 = leaf1.size() , n2 = leaf2.size();
        
        if(n1 != n2)
            return false;
        
        for(int i=0;i<n1;i++)
        {
            if(leaf1[i] != leaf2[i])
                return false;
        }
        
        return true;
        
    }
};