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
    vector<double> averageOfLevels(TreeNode* root) {
        
        vector<double> ans;
        
        if(root==NULL)
            return ans;
        queue<TreeNode*> q;
        q.push(root);
        
        while(q.size())
        {
            int len = q.size() , cntOfNodes = 0 ;
            long sum = 0;
            
            while(len--)
            {
                TreeNode* node = q.front();
                q.pop();
                if(node->left)
                    q.push(node->left);
                if(node->right)
                    q.push(node->right);
                
                sum += (node->val);
                cntOfNodes++;
            }
            
            double avg = (double)sum / (double)cntOfNodes;
            
            ans.push_back(avg);
            
            
        }
        
        return ans;
        
    }
};