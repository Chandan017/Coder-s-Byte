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
    int maxi = 0;
    void solve(TreeNode* root , int dir , int cnt)
    {

        if(!root)
            return ;
        maxi = max(maxi , cnt);

        if(dir == 1)
        {
            solve(root->right , 0 , cnt+1);
            solve(root->left , 1 , 1);
        }
        else
        {
            solve(root->left , 1 , cnt+1);
            solve(root->right , 0 , 1);
        }
        
        
        return ;
    }
    int longestZigZag(TreeNode* root) {
        
        solve(root->left , 1 , 1);
        solve(root->right , 0 , 1);
        
        return maxi;
        
    }
};