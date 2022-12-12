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
    vector<vector<int>> verticalOrder(TreeNode* root) {
        vector<vector<int>> res;
        
        if(!root)
            return res;
        
        map<int , map<int,vector<int>>> mpp;
        
        queue<pair<TreeNode*,int>> q;
        q.push({root , 0});
        
        int level = 0;
        while(q.size())
        {
            int len = q.size();
            while(len--)
            {
                TreeNode* curr = q.front().first;
                int ind = q.front().second;
                q.pop();
                
                mpp[ind][level].push_back(curr->val);
                
                
                if(curr->left)
                    q.push({curr->left , ind-1});
                if(curr->right)
                    q.push({curr->right , ind+1});
            }
            level++;
        }
        
        for(auto ind:mpp)
        {
            vector<int> temp;
            for(auto level:ind.second)
            {
                for(auto ele:level.second)
                    temp.push_back(ele);
            }
            
            res.push_back(temp);
        }
        
        
        
        return res;
        
    }
};