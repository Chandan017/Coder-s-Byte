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
    TreeNode* reverseOddLevels(TreeNode* root) {
        
        if(!root)
            return root;
        
        queue<TreeNode*> q1 , q2;
        q1.push(root);
        q2.push(root);
        bool isOdd = false;
        while(q1.size())
        {
            int len = q1.size();
            vector<int> level;
            while(len--)
            {
                TreeNode* root = q1.front();
                q1.pop();
                
                level.push_back(root->val);
                if(root->left)
                    q1.push(root->left);
                
                if(root->right)
                    q1.push(root->right);
            }
                        
            len = q2.size();
            while(len--)
            {
                TreeNode* root = q2.front();
                q2.pop();
                
                if(isOdd)
                {
                    root->val = level.back();
                    level.pop_back();
                }
                
                if(root->left)
                    q2.push(root->left);
                if(root->right)
                    q2.push(root->right);
                
            }
            
            if(isOdd)
                isOdd = false;
            else
                isOdd = true;
        }
        
        cout<<endl;
              
        return root;
        
    }
};