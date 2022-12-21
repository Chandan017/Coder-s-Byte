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
    int cnt = 0;
    
    vector<int> solve(TreeNode* root , int distance)
    {
        if(!root)
            return {};
        
        if(!root->left && !root->right)
        {
            return {1};
        }
        
        vector<int> l = solve(root->left , distance);
        vector<int> r = solve(root->right , distance);
        vector<int> res;
        
        if(l.size() == 0 && r.size()==0)
            return {};
        
        for(auto i:l)
        {
            for(int j:r)
            {
                if(i+j <= distance)
                    cnt++;
            }
        }
        
        for(auto i:l)
        {
            res.push_back(i+1);
        }
        
        for(auto j:r)
        {
            res.push_back(j+1);
        }
        
        return res;
    }
    int countPairs(TreeNode* root, int distance) {
        
        solve(root , distance);
        
        return cnt;
        
    }
};