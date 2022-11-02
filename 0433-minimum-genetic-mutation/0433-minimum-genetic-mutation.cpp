class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        
        queue<string> q;
        q.push(start);
        
        unordered_set<string> vis(bank.begin() , bank.end());
        int steps = 0;
        string characters = "ACGT";
        while(q.size())
        {
            int len = q.size();
            while(len--)
            {
                string curr = q.front();
                q.pop();
                
                if(curr == end)
                    return steps;
                
                for(int i=0;i<8;i++)
                {
                    
                        char temp = curr[i];
                        
                        for(int j=0;j<characters.length();j++)
                        {
                            curr[i] = characters[j];
                            
                            if(vis.find(curr) != vis.end())
                            {
                                q.push(curr);
                                vis.erase(vis.find(curr));
                            }
                        }
                        
                        curr[i] = temp;
                    }
            }
            
            steps++;
        }
        
        return -1;
        
    }
};