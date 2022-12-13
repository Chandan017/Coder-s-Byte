class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        
        queue<int> q;
        q.push(start);
        int n = arr.size();
        vector<bool> vis(n+1 , false);
        vis[start] = true;
        
        
        while(q.size())
        {
            int curr = q.front();
            q.pop();
            
            if(arr[curr] == 0)
                return true;
            
            if(curr+arr[curr] < n && vis[curr+arr[curr]] == false)
            {
                q.push(curr+arr[curr]);
                vis[curr+arr[curr]] = true;
            }
            
            if(curr-arr[curr]>=0 && vis[curr-arr[curr]] == false)
            {
                q.push(curr-arr[curr]);
                vis[curr-arr[curr]] = true;
            }
        }
        
        
        return false;
        
    }
};