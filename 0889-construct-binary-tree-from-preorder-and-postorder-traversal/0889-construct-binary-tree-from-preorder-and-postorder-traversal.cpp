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
    unordered_map<int,int> getInd;
    int preInd = 0;
    
    TreeNode* solve(vector<int> &preorder , vector<int> &postorder , int start , int end)
    {
        if(start > end)
            return NULL;
        
        if(start == end)
        {
            return new TreeNode(preorder[preInd++]);
        }
        
        TreeNode* root = new TreeNode(preorder[preInd++]);
        int ind2 = getInd[preorder[preInd]];
        
        root->left = solve(preorder , postorder , start , ind2);
        root->right = solve(preorder , postorder , ind2+1 , end-1);
        
        return root;
    }
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        
        int n = postorder.size();
        for(int i=0;i<n;i++)
        {
            getInd[postorder[i]] = i;
        }
        
        TreeNode* res = solve(preorder , postorder , 0 , n-1);
        
        return res;
        
    }
};