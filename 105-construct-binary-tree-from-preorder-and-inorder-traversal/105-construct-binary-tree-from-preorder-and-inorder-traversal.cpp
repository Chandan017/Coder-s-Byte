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
    unordered_map<int,int> mp;
    TreeNode* get(vector<int>& preorder, vector<int>& inorder,int preStart,int preEnd,int inStart,int inEnd)
    {
        if(inStart > inEnd || preStart>preEnd)
            return NULL;
        
        
        TreeNode* root=new TreeNode(preorder[preStart]);
        
        int index=mp[root->val];
        int numsLeft=index-inStart;
        
        root->left=get(preorder,inorder,preStart+1,preStart+numsLeft,inStart,index-1);
        root->right=get(preorder,inorder,preStart+numsLeft+1,preEnd,index+1,inEnd);
        
        return root;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
        
        
        int n=inorder.size();
        int m=preorder.size();
        
        for(int i=0;i<n;i++)
            mp[inorder[i]]=i;
        
        return get(preorder,inorder,0,m-1,0,n-1);
        
    }
};