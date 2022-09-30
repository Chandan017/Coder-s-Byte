class Node{
public:
    
    Node* links[26];
    bool flag;
    
    bool containsKey(char ch)
    {
        return (links[ch-'a'] != NULL);
    }
    
    bool isEnd()
    {
        return flag;
    }
    void setEnd()
    {
        flag = true;
    }
    
    void put(char ch , Node* node)
    {
        links[ch-'a'] = node;
    }
    
    Node* nextLink(char ch)
    {
        return links[ch-'a'];
    }
    
    

};

class Trie {
Node* root ;
public:
    Trie() {
         root = new Node();
    }
    
    void insert(string word) {
        
        Node* node = root;
        
        for(auto c:word)
        {
            if(!node->containsKey(c))
                node->put(c , new Node());
            
            node = node->nextLink(c);
        }
        
        node->setEnd();
        
    }
    
    bool search(string word) {
        
        Node* node = root;
        
        for(auto c:word)
        {
            if(node->containsKey(c))
                node = node->nextLink(c);
            else
                return false;
        }
        
        return (node->isEnd());
        
    }
    
    bool startsWith(string prefix) {
        
        Node* node = root;
        
        for(auto c:prefix)
        {
            if(node->containsKey(c))
                node = node->nextLink(c);
            else
                return false;
        }
        
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */