class Solution {
public:
    int minJumps(vector<int>& arr) {
        
        int n = arr.size();
        vector<bool> vis(n , false);
        unordered_map<int,vector<int>> mpp;
        vis[0] = true;
        
        int jumps = 0;
        
        for(int i=0;i<n;i++)
        {
            mpp[arr[i]].push_back(i);
        }
        
        
        queue<int> q;
        q.push(0);
        
        while(q.size())
        {
            int len = q.size();
            while(len--)
            {
                int curr = q.front();
                q.pop();
                
                if(curr == n-1)
                    return jumps;
                
                if(curr+1 < n && vis[curr+1] == false)
                {
                    q.push(curr+1);
                    vis[curr+1] = true;
                }
                
                if(curr-1 >=0 && vis[curr-1] == false)
                {
                    q.push(curr-1);
                    vis[curr-1] = true;
                }
                
                vector<int> &sameVal = mpp[arr[curr]];
                
                for(auto j:sameVal)
                {
                    if(vis[j] == false)
                    {
                        q.push(j);
                        vis[j] = true;
                    }
                }
                
                sameVal.clear();
            }
            jumps++;
        }
        
        return -1;
        
    }
};