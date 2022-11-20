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
    vector<int> inorder;
    
    void getInorder(TreeNode* root)
    {
        if(!root)
            return ;
        getInorder(root->left);
        
        inorder.push_back(root->val);
        
        getInorder(root->right);
        
        return ;
    }
    vector<vector<int>> closestNodes(TreeNode* root, vector<int>& queries) {
        
        
        vector<vector<int>> res;
        
        getInorder(root);
        
        for(auto q:queries)
        {
            int mini = INT_MAX , maxi = INT_MIN;
            
            int l = 0 , h = inorder.size()-1;
            
            while(l<=h)
            {
                int mid = l+(h-l) / 2;
                
                if(inorder[mid] == q)
                {
                    mini = inorder[mid];
                    maxi = inorder[mid];
                    break;
                }
                else if(inorder[mid] < q)
                {
                    maxi = max(maxi , inorder[mid]);
                    l = mid+1;
                }
                else
                {
                    mini = min(mini , inorder[mid]);
                    h = mid-1;
                }
            }
            
            if(mini == INT_MAX)
                mini = -1;
            if(maxi == INT_MIN)
                maxi = -1;
            
            res.push_back({maxi , mini});
        }
    
        
        return res;
    }
};