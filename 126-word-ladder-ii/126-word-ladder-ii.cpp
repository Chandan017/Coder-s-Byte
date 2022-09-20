class Solution {
public:
    map<string,int> stepMap;
    vector<vector<string>> res;
    
    int getMinSteps(string &beginWord , string &endWord , vector<string> &wordList)
    {
        queue<string> q;
        q.push(beginWord);
        unordered_set<string> vis(wordList.begin() , wordList.end());
        if(vis.find(beginWord) != vis.end())
            vis.erase(vis.find(beginWord));
        
        if(vis.find(endWord) == vis.end())
            return -1;
        
        int minSteps = -1;
        int level = 0;
        
        while(q.size())
        {
            int len = q.size();
            while(len--)
            {
                string curr = q.front();
                q.pop();
                
                stepMap[curr] = level;
                
                if(curr==endWord)
                {
                    if(minSteps == -1)
                        minSteps = level;
                    continue;
                }
                
                for(int ind=0;ind<curr.length();ind++)
                {
                    char original = curr[ind];
                    for(char ch='a';ch<='z';ch++)
                    {
                        curr[ind] = ch;
                        if(vis.find(curr) != vis.end())
                        {
                            q.push(curr);
                            vis.erase(vis.find(curr));
                        }
                    }
                    curr[ind] = original;
                }
            }
            level++;
        }
        
        return minSteps;
    }
    
//     void generatePath(string src , string &dest , vector<string> currPath , int totalSteps)
//     {
//         if(src == dest)
//         {
//             reverse(currPath.begin() , currPath.end());
//             res.push_back(currPath);
//             return ;
//         }
       
//         for(int ind=0;ind<src.length();ind++)
//         {
//             char original = src[ind];
//             for(char ch='a';ch<='z';ch++)
//             {
//                 src[ind] = ch;
//                 if(stepMap.find(src) != stepMap.end() && stepMap[src] == (totalSteps-1))
//                 {
//                     currPath.push_back(src);
//                     generatePath(src , dest , currPath , totalSteps-1);
//                     currPath.pop_back();
//                 }
//             }
//             src[ind] = original;
//         }
//         return ;
        
//     }
    
    
    void generatePath(string src , string dest , int minSteps)
    {
        vector<string> currPath;
        currPath.push_back(src);
        queue<vector<string>> q;
        q.push(currPath);
        
        while(q.size())
        {
            int len = q.size();
            while(len--)
            {
                vector<string> curr = q.front();
                q.pop();
                
                string lastWord = curr.back();
                
                if(lastWord == dest)
                {
                    reverse(curr.begin() , curr.end());
                    res.push_back(curr);
                    continue;
                }
                
                for(int ind=0;ind<lastWord.length();ind++)
                {
                    char original = lastWord[ind];
                    
                    for(char ch='a';ch<='z';ch++)
                    {
                        lastWord[ind] = ch;
                        if(stepMap.find(lastWord) != stepMap.end() && stepMap[lastWord]==minSteps-1)
                        {
                            curr.push_back(lastWord);
                            q.push(curr);
                            curr.pop_back();
                        }
                    }
                    lastWord[ind] = original;
                }
            }
            minSteps--;
        }
        
        return ;
        
    }
    
    
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        
        
        int minSteps = getMinSteps(beginWord , endWord , wordList);
        
     
        if(minSteps == -1)
            return res;
        
        vector<string> currPath;
        currPath.push_back(endWord);
        
        generatePath(endWord , beginWord , minSteps);
        
        return res;
    }
};