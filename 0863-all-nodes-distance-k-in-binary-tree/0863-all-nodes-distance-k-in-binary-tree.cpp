/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    unordered_map<int,TreeNode*> parent;
    
    void getParent(TreeNode* root)
    {
        queue<TreeNode*> q;
        q.push(root);
        
        while(q.size())
        {
            TreeNode* curr = q.front();
            q.pop();
            
            if(curr->left)
            {
                q.push(curr->left);
                parent[curr->left->val] = curr;
                
            }
            
            if(curr->right)
            {
                q.push(curr->right);
                parent[curr->right->val] = curr;
            }
        }
        
        return ;
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        
        
        getParent(root);
        
        queue<TreeNode*> q;
        q.push(target);
        
        unordered_set<int> vis;
        vis.insert(target->val);
        
        int dist = 0;
        vector<int> res;
        
        while(q.size())
        {
            int len = q.size();
            while(len--)
            {
                TreeNode* curr = q.front();
                q.pop();
                
                if(dist == k)
                {
                    res.push_back(curr->val);
                }
                
                
                if(curr->left && vis.find(curr->left->val) == vis.end())
                {
                    q.push(curr->left);
                    vis.insert(curr->left->val);
                }
                
                if(curr->right && vis.find(curr->right->val) == vis.end())
                {
                    q.push(curr->right);
                    vis.insert(curr->right->val);
                }
                
                if(parent[curr->val] && vis.find(parent[curr->val]->val) == vis.end())
                {
                    q.push(parent[curr->val]);
                    vis.insert(parent[curr->val]->val);
                }
            }
            
            dist++;
        }
        
        return res;
        
    }
};