class Node{
public:
    
    Node* links[26];
    int cnt = 0;
    int wordEnd = 0;
    
    bool containsKey(char ch)
    {
        return (links[ch-'a'] != NULL);
    }
    
    bool isEnd()
    {
        return (cnt>0);
    }
    void setEnd()
    {
        cnt++;
    }
    
    void put(char ch )
    {
        links[ch-'a'] = new Node();
    }
    
    Node* nextLink(char ch)
    {
        return links[ch-'a'];
    }
    
    void decCnt()
    {
        cnt--;
    }
    
    void del(char ch)
    {
        links[ch-'a'] = NULL;
    }
    
    

};


class Trie {
public:
Node* root = new Node();
    Trie() {
        
    }
    
    void insert(string word) {
        
        Node* node = root;
        
        for(auto c:word)
        {
            if(!node->containsKey(c))
                node->put(c);
            node = node->nextLink(c);
            
            node->setEnd();
        }
        node->wordEnd++;
        return ;
        
    }
    
    int countWordsEqualTo(string word) {
        
        Node* node = root;
        
        for(auto c:word)
        {
            if(node->containsKey(c))
                node = node->nextLink(c);
            else
                return 0;
        }
        
        
        return node->wordEnd;
        
    }
    
    int countWordsStartingWith(string prefix) {
        
        Node* node = root;
        
        for(auto c:prefix)
        {
            if(node->containsKey(c))
                node = node->nextLink(c);
            else
                return 0;
        }
        return node->cnt;
        
    }
    
    void erase(string word) {
        
        Node* node = root;
        
        for(auto c:word)
        {
            Node* next = node->nextLink(c);
            next->decCnt();
            if(next->cnt == 0)
                node->links[c-'a'] = NULL;
            node = next;
        }
        
        node->wordEnd--;
        // node->decCnt();
        return ;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * int param_2 = obj->countWordsEqualTo(word);
 * int param_3 = obj->countWordsStartingWith(prefix);
 * obj->erase(word);
 */