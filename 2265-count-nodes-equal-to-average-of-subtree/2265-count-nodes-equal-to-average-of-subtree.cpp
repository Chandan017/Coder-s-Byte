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
    int n = 0;
    
    int getAverage(TreeNode* root)
    {
        if(root==NULL)
            return 0;
        
        n++;
        int sum = root->val;
        sum += getAverage(root->left);
        sum += getAverage(root->right);
        
        return sum;
    }
    
    
    
    
    int averageOfSubtree(TreeNode* root) {
        
        if(root==NULL)
            return 0;
        
        n = 0;
        int average = getAverage(root);
        
        int cnt = 0;
        if(average/n == root->val)
            cnt++;
        
        cnt += averageOfSubtree(root->left);
        cnt += averageOfSubtree(root->right);
        
        return cnt;
        
    }
};