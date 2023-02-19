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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        
        if(!root)
            return res;
        
        queue<TreeNode*> q;
        q.push(root);
        
        bool flag = false;
        while(q.size())
        {
            vector<int> temp;
            int len = q.size();
            while(len--)
            {
                TreeNode* curr = q.front();
                q.pop();
                
                if(curr->left)
                    q.push(curr->left);
                if(curr->right)
                    q.push(curr->right);
                
                temp.push_back(curr->val);
            }
            
            if(flag)
                reverse(temp.begin() , temp.end());
            
            res.push_back(temp);
            flag = !flag;
        }
        
        
        
        return res;
        
    }
};