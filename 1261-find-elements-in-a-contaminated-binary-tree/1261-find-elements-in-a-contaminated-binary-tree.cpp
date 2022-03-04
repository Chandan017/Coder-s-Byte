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
class FindElements {
public:
    
    set<int> s;
    FindElements(TreeNode* root) {
        
        queue<pair<TreeNode* , long>> q;
        if(root!=NULL)
        {
            q.push({root , 0});
            s.insert(0);
        }
            
        
        while(!q.empty())
        {
            TreeNode* node=q.front().first;
            long ind=q.front().second;
            q.pop();
            
            if(node->left)
            {
                q.push({node->left , 2*ind +1});
                s.insert(2*ind+1);
            }
            
            if(node->right)
            {
                q.push({node->right , 2*ind+2});
                s.insert(2*ind+2);
            }
        }
    }
    
    bool find(int target) {
        
        if(s.find(target)!=s.end())
            return true;
        return false;
        
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */