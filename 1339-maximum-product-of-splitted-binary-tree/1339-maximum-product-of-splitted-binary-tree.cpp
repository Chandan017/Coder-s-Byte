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
    vector<long> sums;
    
    long getSum(TreeNode* root)
    {
        if(!root)
            return 0;
        
        long l = getSum(root->left);
        long r = getSum(root->right);
        
        long totalSum = l + r + root->val;
        sums.push_back(totalSum);
        return totalSum;
    }
    int maxProduct(TreeNode* root) {
        
        if(!root)
            return 0;
        
        long totalSum = getSum(root);
        long maxProduct = 0;
        int mod = 1e9+7;
        for(auto it:sums)
        {
            long currProduct = it * (totalSum - it);
            maxProduct = max(maxProduct , currProduct);
        }
        
        
        return (maxProduct%mod);
        
         
    }
};