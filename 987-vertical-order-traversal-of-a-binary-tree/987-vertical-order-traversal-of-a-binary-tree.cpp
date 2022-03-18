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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,map<int,multiset<int>>> mpp;
        vector<vector<int>> ans;
        
        if(root==NULL)
            return ans;
        
        queue<pair<TreeNode*,pair<int,int>>> q;
        q.push({root , {0,0}});  // node , level , vertical axis
        
        while(!q.empty())
        {
            TreeNode* node=q.front().first;
            int level=q.front().second.first;
            int axis=q.front().second.second;
            q.pop();
            
            if(node->left)
            {
                q.push({node->left , {level+1 , axis-1}});
            }
            if(node->right)
            {
                q.push({node->right , {level+1 , axis+1}});
            }
            
            mpp[axis][level].insert(node->val);
            
        }
        
        for(auto &it:mpp)
        {
            vector<int> temp;
            
            for(auto &j:it.second)
            {
                temp.insert(temp.end() , j.second.begin() , j.second.end());
            }
            ans.push_back(temp);
        }
        return ans;
        
    }
};