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
    int maxLevelSum(TreeNode* root) {
        
        pair<int,int> ans={INT_MIN,-1};
        
        queue<TreeNode*> q;
        q.push(root);
       
        int level=1;
        while(!q.empty())
        {
            int size=q.size();
             long long sum=0;
            while(size--)
            {
                TreeNode* node=q.front();
                q.pop();
                
                if(node->left)
                    q.push(node->left);
                if(node->right)
                    q.push(node->right);
                
                sum+=node->val;
            }
        
           
            if(sum > ans.first)
            {
                ans.first=sum;
                ans.second=level;
            }
            level++;
            
        }
        
        return ans.second;
        
        
    }
};