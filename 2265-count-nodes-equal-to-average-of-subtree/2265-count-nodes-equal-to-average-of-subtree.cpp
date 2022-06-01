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
    int n=0;;
    int getAverage(TreeNode* root)
    {
        if(root==NULL)
            return 0;
        
        int sum = root->val;
        n++;
        
        sum += getAverage(root->left);
        sum += getAverage(root->right);
        
        return sum;
        
    }
    int averageOfSubtree(TreeNode* root) {
        
        if(root==NULL)
            return 0;
        
        n=0;
        int ans = 0;
        int curr = getAverage(root);
        if(curr/n == root->val)
            ans++;
        
        ans += averageOfSubtree(root->left);
        ans +=averageOfSubtree(root->right);
        
        return ans;
        
    }
};