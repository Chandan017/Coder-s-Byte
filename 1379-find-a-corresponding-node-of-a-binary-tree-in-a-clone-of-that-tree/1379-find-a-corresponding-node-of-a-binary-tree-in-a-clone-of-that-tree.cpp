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
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        
        queue<pair<TreeNode* , TreeNode*>> q;
        q.push({original , cloned});
        
        while(!q.empty())
        {
            TreeNode* origin=q.front().first;
            TreeNode* duplicate=q.front().second;
            q.pop();
            
            if(origin==target)
                return duplicate;
            
            if(origin->left)
            {
                q.push({origin->left , duplicate->left});
                
            }
            
            if(origin->right)
                q.push({origin->right , duplicate ->right});
        }
        
        return NULL;
        
    }
};