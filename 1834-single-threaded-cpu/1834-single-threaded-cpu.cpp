class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        
        int n=tasks.size();
        
        
        for(int i=0;i<n;i++)
            tasks[i].push_back(i);
        
        sort(tasks.begin() , tasks.end());
        
        long currTime = 0;
        
        priority_queue<pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>> > pq;
        
        int ind =0;
        vector<int> ans;
       
        while( ind < n || !pq.empty())
        {
           if(pq.size()==0 )
               currTime = max (currTime  , (long)tasks[ind][0]);
               
            
            while(ind < n && tasks[ind][0] <= currTime)
            {
                pq.push({tasks[ind][1] , tasks[ind][2]});
                ind++;
            }
            
            int processTime = pq.top().first;
            int index = pq.top().second;
            pq.pop();
            
            currTime += processTime;
            
            ans.push_back(index);
        }
        
        return ans;
    }
};