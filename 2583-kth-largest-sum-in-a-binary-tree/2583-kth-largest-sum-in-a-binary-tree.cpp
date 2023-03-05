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
    long long kthLargestLevelSum(TreeNode* root, int k) {
        
        priority_queue<long long> pq;
        queue<TreeNode*> q;
        q.push(root);
        
        while(q.size())
        {
            int len = q.size();
            long long currSum = 0;
            
            while(len--)
            {
                TreeNode* curr = q.front();
                q.pop();
                
                if(curr->left)
                    q.push(curr->left);
                if(curr->right)
                    q.push(curr->right);
                
                currSum += curr->val;
            }
            
            pq.push(-currSum);
            
            if(pq.size() > k)
                pq.pop();
        }
        
        if(pq.size() < k)
            return -1;
        
        return abs(pq.top());
        
    }
};