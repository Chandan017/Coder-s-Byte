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

    int cnt=0;
    // 1 means covered by another camera 
    // 2 means camera installed
    // 0 means not covered with camera and needed to be installed;
    int get(TreeNode* root)
    {
        if(root==NULL)
            return 1;
        
        int l=get(root->left);
        int r=get(root->right);
        
        if(l==0 || r==0)
        {
            cnt++;
            return 2;
        }
        else if(l==2 || r==2)
            return 1;
        return 0;
    }
    
    int minCameraCover(TreeNode* root) {
           
    
        if(root==NULL)
            return 0;
        
        int ans=get(root);
        if(ans==0)
            return cnt+1;
        
        return cnt;
        
    }
};