/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        
        string tree = "";
        if(root==NULL)
            return "";
        
        queue<TreeNode*> q;
        q.push(root);
        
        while(q.size())
        {
            root = q.front();
            q.pop();
            if(root)
            {
                q.push(root->left);
                q.push(root->right);
            }
            
            if(root==NULL)
                tree += '#';
            else
                tree += to_string(root->val);
            
            tree+=',' ;
        }
        
        cout<<tree<<endl;
        
        return tree;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
    
        if(data.length()==0)
            return NULL;
        
        stringstream s(data);
        string str;
        
        getline(s , str , ',');
        TreeNode* root = new TreeNode(stoi(str));
        queue<TreeNode*> q;
        q.push(root);
        
        while(q.size())
        {
            TreeNode* node = q.front();
            q.pop();
            
            getline(s , str , ',');
            
            if(str=="#")
                node->left = NULL;
            else
            {
                TreeNode* leftNode = new TreeNode(stoi(str));
                node->left = leftNode;
                q.push(leftNode);
            }
            
            getline(s , str , ',');
            
            if(str=="#")
                node->right = NULL;
            else
            {
                TreeNode* rightNode = new TreeNode(stoi(str));
                node->right = rightNode;
                q.push(rightNode);
            }
                
        }
        
        return root;
        
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));