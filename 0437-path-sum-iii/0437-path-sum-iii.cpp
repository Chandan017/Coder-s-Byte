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
    // int cnt = 0;
    
    int solve(TreeNode* root , long targetSum)
    {
        if(!root)
            return 0;
        
        targetSum -= root->val;
        
        int cnt = 0;
        if(targetSum == 0)
            cnt++;
        
        
        cnt += solve(root->left , targetSum);
        cnt += solve(root->right , targetSum);
        
        return cnt;
    }
    int pathSum(TreeNode* root, int targetSum) {
        
        if(!root)
            return 0;
        
        int res = solve(root , targetSum);
        
        res += pathSum(root->left , targetSum);
        res += pathSum(root->right , targetSum);
        
        return res;
        
       
    }
};