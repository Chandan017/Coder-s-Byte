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

    int cnt = 0;
    
    void getPath(TreeNode* root , string s)
    {
       
        if(!root->left && !root->right)
        {
            if(s[root->val] == '1')
                s[root->val] = '0';
            else
                s[root->val] = '1';
            
            int curr = 0;
            for(auto &it:s)
            {
                if(it=='1')
                    curr++;
            }
            
            if(curr<=1)
                cnt++;
            
           
            return ;
        }
        
        if(s[root->val] == '1')
                s[root->val] = '0';
        else
            s[root->val] = '1';
        
        
        if(root->left)
            getPath(root->left , s);
        if(root->right)
            getPath(root->right , s);
        return ;
        
    }
    
   
    int pseudoPalindromicPaths (TreeNode* root) {
        string s = "0000000000";
        getPath(root , s);
       
        return cnt;
        
    }
};