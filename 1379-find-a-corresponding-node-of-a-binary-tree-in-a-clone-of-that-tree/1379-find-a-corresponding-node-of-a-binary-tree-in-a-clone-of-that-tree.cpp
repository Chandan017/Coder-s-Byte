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
    
    TreeNode* ans;
    void check(TreeNode* &o , TreeNode* &c , TreeNode* &target)
    {
        if(o==NULL)
            return ;
        check(o->left , c->left , target);
        
        if(o==target)
        {
            ans=c;
            return ;
        }
        
        check(o->right , c->right , target);
        return ;
    }
    
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        
        
        check(original , cloned , target);
        
        return ans;
        
    }
};