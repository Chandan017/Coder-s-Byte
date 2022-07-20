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
    
    
    
    
    vector<int> preorderTraversal(TreeNode* root) {
        
        vector<int> ans;
        
        if(root==NULL)
            return ans;
        
        stack<TreeNode*> st;
        st.push(root);
        
        while(st.size())
        {
            TreeNode* node = st.top();
            st.pop();
            
            if(node->right)
                st.push(node->right);
            if(node->left)
                st.push(node->left);
            
            ans.push_back(node->val);
        }
        
        return ans;
        
    }
};