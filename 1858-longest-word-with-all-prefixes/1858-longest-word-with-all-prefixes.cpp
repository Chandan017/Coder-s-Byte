
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

class Trie{
public:
Node* root = new Node();
    
    void insert(string s)
    {
        Node* node = root;
        
        for(auto c:s)
        {
            if(!node->containsKey(c))
                node->put(c , new Node());
            node = node->nextLink(c);
        }
        
        node->setEnd();
    }
    
    bool checkPrefix(string s)
    {
        Node* node = root;
        
        for(auto c:s)
        {
            if(node->containsKey(c))
                node = node->nextLink(c);
            else
                return false;
            if(node->isEnd() == false)
                return false;
        }
                
        return true;
    }
};

class Solution {
public:
    string longestWord(vector<string>& words) {
        
        Trie* trie = new Trie();
        
        for(auto it:words)
        {
            trie->insert(it);
        }
        
        string res = "";
        for(auto word:words)
        {
           bool check = trie->checkPrefix(word);
            
            if(check)
            {
                if(word.length() == res.length())
                    res = min(res , word);
                else if(word.length() > res.length())
                    res = word;
            }
        }
        
        // cout<<endl;
        return res;
        
    }
};