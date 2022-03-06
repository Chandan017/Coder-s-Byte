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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        
        unordered_map<int,TreeNode*> mpp;
        unordered_set<TreeNode*> allNodes;
        unordered_map<TreeNode* , TreeNode*> cToP;
       
        for(auto &it:descriptions)
        {
            int par=it[0] , child=it[1];
            bool isLeft=it[2];
            
            TreeNode* node;
            TreeNode* bccha;
            if(mpp.find(par)==mpp.end())
            {
               node=new TreeNode(par);
                if(mpp.find(child)==mpp.end())
                {
                    bccha =new TreeNode(child);
                    mpp[child]=bccha;
                    
                }
                else
                    bccha=mpp[child];
                
                if(isLeft)
                    node->left=bccha;
                else
                    node->right=bccha;
                
                mpp[par]=node;
                
                
                
                
            }
            else
            {
                node=mpp[par];

                
                if(mpp.find(child)==mpp.end())
                {
                    bccha=new TreeNode(child);
                    mpp[child]=bccha;
                    
                }
                else
                {
                    bccha=mpp[child];
                  
                       
                }
                    
                
                if(isLeft)
                    node->left=bccha;
                else
                    node->right=bccha;
                
              
            }
            
            cToP[bccha]=node;
            allNodes.insert(node);
            allNodes.insert(bccha);
            
            

            
        }
        
        
        for(auto &it:allNodes)
        {
            if(cToP.find(it)==cToP.end())
                return it;
        }
       
        
        return NULL;
        
    }
};