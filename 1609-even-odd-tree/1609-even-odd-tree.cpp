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
    bool isEvenOddTree(TreeNode* root) {
        
        queue<TreeNode*> q;
        q.push(root);
        bool isEven = true;
        while(q.size())
        {
            int prev = (isEven)?INT_MIN:INT_MAX;
            int len = q.size();

            while(len--)
            {
                root = q.front();
                q.pop();

                if(root->left)
                    q.push(root->left);
                if(root->right)
                    q.push(root->right);

                if(isEven)
                {
                    if(root->val%2==1 && root->val > prev)
                        prev = root->val;
                    else
                        return 0;
                }
                else
                {
                    if(root->val%2==0 && root->val < prev)
                        prev = root->val;
                    else
                        return 0;
                }
            }

            isEven = !isEven;
        }

        return 1;
        
    }
};