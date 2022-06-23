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
    bool isCousins(TreeNode* root, int x, int y) {
        
        queue<TreeNode*> q;
        q.push(root);
        
        int depthX , depthY;
        int parentX , parentY;
        
        int depth = 0;
        while(q.size())
        {
            int len = q.size();
            while(len--)
            {
                TreeNode* node = q.front();
                q.pop();
                if(node->left)
                {
                    q.push(node->left);
                    
                    if(node->left->val == x)
                        parentX = node->val;
                    
                    if(node->left->val == y)
                        parentY = node->val;
                }
                
                if(node->right)
                {
                    q.push(node->right);
                    
                    if(node->right->val == x)
                        parentX = node->val;
                    if(node->right->val == y)
                        parentY = node->val;
                    
                }
                
                if(node->val == x)
                    depthX = depth;
                if(node->val == y)
                    depthY = depth;
                   
                
            }
            depth++;
        }
        
        
        if(depthX==depthY && parentX != parentY)
            return true;
        else
            return false;
        
    }
};