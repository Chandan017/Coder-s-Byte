class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        
        queue<string> q;
        q.push(beginWord);
        set<string> list(wordList.begin() , wordList.end());
        set<string> vis;
        vis.insert(beginWord);
        int steps = 1;
        while(q.size())
        {
            int len = q.size();
            while(len--)
            {
                string curr = q.front();
                q.pop();
                
                if(curr == endWord)
                    return steps;
                string temp = curr;
                for(int i=0;i<curr.length();i++)
                {
                    for(char c='a';c<='z';c++)
                    {
                        curr[i] = c;
                        
                        if(list.find(curr) != list.end() && vis.find(curr) == vis.end())
                        {
                            vis.insert(curr);
                            q.push(curr);
                        }
                    }
                    
                    curr = temp;
                }
                
            }
            steps++;
        }
        
        return 0;
        
    }
};