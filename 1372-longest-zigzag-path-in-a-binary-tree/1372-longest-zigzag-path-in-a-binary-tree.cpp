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
    void solve(TreeNode* root , string prevDir , int cnt)
    {

        if(!root)
            return ;
        maxi = max(maxi , cnt+1);

        if(prevDir == "left")
        {
            solve(root->right , "right" , cnt+1);
            solve(root->left , "left" , 0);
        }
        else
        {
            solve(root->left , "left" , cnt+1);
            solve(root->right , "right" , 0);
        }
        
        
        return ;
    }
    int longestZigZag(TreeNode* root) {
        
        if(root->left)
        {
            solve(root->left , "left" , 0);
        }
        
        if(root->right)
        {
            solve(root->right , "right" , 0);
        }
        
        return maxi;
        
    }
};