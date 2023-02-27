/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
public:
    Node* solve(int l,int r,int t,int b, vector<vector<int>> &v){
        if(l==r || t==b ){
            return new Node(v[t][l],true);
        }
        Node* root= new Node(1,false);
        root->topLeft=solve(l,(r+l)/2,t,(b+t)/2,v);
        root->topRight=solve(((r+l)/2)+1,r,t,(b+t)/2,v);
        root->bottomLeft=solve(l,(r+l)/2,((b+t)/2)+1,b,v);
        root->bottomRight=solve(((r+l)/2)+1,r,(b+t)/2+1,b,v);
        if(root->topLeft->val == root->topRight->val && 
           root->topLeft->val == root->bottomLeft->val &&
           root->topLeft->val == root->bottomRight->val &&
           root->topLeft->isLeaf && root->topRight->isLeaf &&
           root->bottomLeft->isLeaf && root->bottomRight->isLeaf){
               return new Node(root->topLeft->val,true);
        }
        return root;
    }
    Node* construct(vector<vector<int>>& v) {
        int n=v.size();
        return solve(0,n-1,0,n-1,v);
    }
};