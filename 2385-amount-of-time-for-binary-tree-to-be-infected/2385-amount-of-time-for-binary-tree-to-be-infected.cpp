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
    
    unordered_map<int,TreeNode*> parent;
    
    TreeNode* getStart(TreeNode* root , int start)
    {
        TreeNode* startNode;
        
        queue<TreeNode*> q;
        q.push(root);
        
        while(q.size())
        {
            TreeNode* curr = q.front();
            q.pop();
            
            if(curr->val == start)
            {
                startNode = curr;
            }
            
            if(curr->left)
            {
                q.push(curr->left);
                parent[curr->left->val] = curr; 
            }
            
            if(curr->right)
            {
                q.push(curr->right);
                parent[curr->right->val] = curr;
            }
        }
        
        
        return startNode;
    }
    int amountOfTime(TreeNode* root, int start) {
        
        
        TreeNode* startNode = getStart(root , start);
        
        queue<TreeNode*> q;
        q.push(startNode);
        
        unordered_set<int> isInfected;
        isInfected.insert(start);
        int totalTime = 0;
        
        while(q.size())
        {
            int len = q.size();
            while(len--)
            {
                TreeNode* curr = q.front();
                q.pop();
                
                // cout<<(curr->val)<<" ";
                
                if(curr->left && isInfected.find(curr->left->val) == isInfected.end())
                {
                    q.push(curr->left);
                    isInfected.insert(curr->left->val);
                }
                
                if(curr->right && isInfected.find(curr->right->val) == isInfected.end())
                {
                    q.push(curr->right);
                    isInfected.insert(curr->right->val);
                }
                
                if(parent[curr->val] && isInfected.find(parent[curr->val]->val) == isInfected.end())
                {
                    q.push(parent[curr->val]);
                    isInfected.insert(parent[curr->val]->val);
                }
            }
            
            // cout<<endl;
            totalTime++;
        }
        
        return totalTime-1;
    }
};