class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        
        int n=tasks.size();
        
        for(int i=0;i<n;i++)
            tasks[i].push_back(i);
        
        sort(tasks.begin() , tasks.end());
        
        long currTime = tasks[0][0];
        int ind=0;
        
        priority_queue<pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>> > pq;
        vector<int> ans;
        
        
        while(ind < n ||  pq.size() > 0)
        {
            if(pq.size()==0)
                currTime = max(currTime , (long)tasks[ind][0]);
            
            while(ind < n && tasks[ind][0] <=currTime)
            {
                pq.push({tasks[ind][1] , tasks[ind][2]});
                ind++;
            }
            
            int time = pq.top().first;
            int index = pq.top().second;
            pq.pop();
            
            currTime += time;
            
            ans.push_back(index);
        }
        
        return ans;
            
        
    }
};