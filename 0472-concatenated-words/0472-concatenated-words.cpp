class Solution {
public:
    
    
    
    class Node{
    public:
        Node* links[26];
        bool flag = false;
        
        bool containsKey(char ch)
        {
            return links[ch-'a'];
        }
        
        void putKey(char ch)
        {
            links[ch-'a'] = new Node();
        }
        
        Node* nextLink(char ch)
        {
            return links[ch-'a'];
        }
        
        void setEnd()
        {
            flag = true;
        }
        
        bool isEnd()
        {
            return flag;
        }
        
    };
    
    class Trie{
    public:
        Node* root = new Node();
        
        void insert(string &word)
        {
            Node* dummy = root;
            
            for(auto &it:word)
            {
                if(!dummy->containsKey(it))
                    dummy->putKey(it);
                dummy = dummy->nextLink(it);
            }
            
            dummy->setEnd();
        }
        
        bool search(string &word)
        {
            Node* dummy = root;
            
            for(auto &it:word)
            {
                if(dummy->containsKey(it))
                    dummy = dummy->nextLink(it);
                else
                    return false;
            }
            
            return dummy->isEnd();
        }
        
        bool find(string &word , string curr , int ind , int cnt)
        {
            if(ind == word.length())
            {
                
                if(cnt >= 2 && curr == "")
                    return true;
                return false;
            }
            
            curr += word[ind];
            ind += 1;
            if(search(curr))
            {
                bool takeIt = find(word , "" , ind, cnt+1);
                
                if(takeIt)
                    return true;
            }
            
            bool notTakeIt = find(word , curr , ind, cnt);
            
            return notTakeIt;
        }
        
    };
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        
        
        vector<string> res;
        
        Trie* trie = new Trie();
        
        for(auto it:words)
        {
            trie->insert(it);
        }

        
        
        for(auto it:words)
        {
            if(trie->find(it , "" , 0 , 0))
                res.push_back(it);
        }
        

        
        return res;
        
    }
};