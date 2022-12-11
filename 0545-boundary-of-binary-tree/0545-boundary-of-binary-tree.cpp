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
    vector<int> res;
    bool isLeaf(TreeNode* root)
    {
        return (!root->left && !root->right);
        
    }
    void getLeft(TreeNode* root)
    {
        while(root)
        {
            if(!isLeaf(root))
                res.push_back(root->val);
            
            if(root->left)
                root = root->left;
            else
                root = root->right;
        }
        
        return ;
    }
    
    void getLeafs(TreeNode* root)
    {
        if(!root)
            return ;
        getLeafs(root->left);
        getLeafs(root->right);
        
        if(isLeaf(root))
            res.push_back(root->val);
        return ;
    }
    
    void getRight(TreeNode* root)
    {
        stack<int> st;
        while(root)
        {
            if(!isLeaf(root))
                st.push(root->val);
            if(root->right)
                root = root->right;
            else
                root = root->left;
        }
        
        while(st.size())
        {
            res.push_back(st.top());
            st.pop();
        }
        
        return ;
    }
    vector<int> boundaryOfBinaryTree(TreeNode* root) {
        
        if(!isLeaf(root))
            res.push_back(root->val);
        
        getLeft(root->left);
        getLeafs(root);
        getRight(root->right);
        
        
        return res;
    }
};