class Node{
public:
    
    Node* links[26];
    int prefixCnt = 0;
    
    bool containsKey(char ch)
    {
        return links[ch-'a'];
    }
    
    void put(char ch)
    {
        links[ch-'a'] = new Node();
    }
    
    Node* nextLink(char ch)
    {
        return links[ch-'a'];
    }
    
    void incPrefix()
    {
        prefixCnt++;
    }
    
    int getPrefix()
    {
        return prefixCnt;
    }
    
    
    
};

class Trie{
Node* root ;
    
public:
    
    Trie()
    {
        root = new Node();
    }
    
    void insert(string word)
    {
        Node* node = root;
        
        for(auto c:word)
        {
            if(!node->containsKey(c))
                node->put(c);
            node = node->nextLink(c);
            
            node->incPrefix();
        }
    }
    
    
    int getPrefixCnt(string &word)
    {
        Node* node = root;
        int totalCnt = 0;
        for(auto c:word)
        {
            if(node->containsKey(c))
                node = node->nextLink(c);
            else
                return 0;
            
            totalCnt += node->getPrefix();
        }
        
        return totalCnt;
    }
};


class Solution {
public:
    vector<int> sumPrefixScores(vector<string>& words) {
        
        Trie* trie = new Trie();
        
        for(auto &it:words)
            trie->insert(it);
        
        vector<int> res;
        
        for(auto &w:words)
        {
            int preCnt = trie->getPrefixCnt(w);
            res.push_back(preCnt);
        }
        
        
        return res;
        
    }
};