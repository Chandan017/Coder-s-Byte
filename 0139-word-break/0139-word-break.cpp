class Node{
public:
    Node* links[26];
    bool flag = false;
    
    bool containsKey(char ch)
    {
        return (links[ch-'a']!=NULL);
    }
    
    void put(char ch)
    {
        links[ch-'a'] = new Node();
    }
    
    Node* nextLink(char ch)
    {
        return links[ch-'a'];
    }
    
    bool isEnd()
    {
        return flag;
    }
    
    void setEnd()
    {
        flag = true;
    }
};

class Trie{
    Node* root;
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
        }
        
        node->setEnd();
    }
    
    bool search(string word)
    {
        Node* node = root;
        
        for(auto c:word)
        {
            if(node->containsKey(c))
                node = node->nextLink(c);
            else
                return false;
        }
        
        return node->isEnd();
    }
    
    
    bool searchWord(string word , int ind , int n , vector<int> &dp)
    {
        if(ind == n)
            return true;
        
        if(dp[ind] != -1)
            return dp[ind];
        
        string curr = "";
        
        for(int i = ind;i<n;i++)
        {
            curr += word[i];
            
            if(search(curr))
            {
                if(searchWord(word , i+1 , n , dp))
                    return dp[ind] = true;
            }
        }
        
        return dp[ind] = false;
    }
    
    
    
};

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        
        Trie* trie = new Trie();
        
        for(auto word:wordDict)
        {
            trie->insert(word);
        }
        int  n = s.length();
        
        vector<int> dp(n+1 , -1);
        bool res = trie->searchWord(s , 0 , n , dp);
        
        return res;
        
    }
};