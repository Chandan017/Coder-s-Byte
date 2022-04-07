class Solution {
public:

// class CPU{
// public:
//     int processTime ;
//     int index;
    
//     CPU(int processTime , int index)
//     {
//         this->processTime = processTime ;
//         this->index = index;
//     }
// };
    vector<int> getOrder(vector<vector<int>>& tasks) {
        
        int n = tasks.size();
        vector<int> ans;
        
        for(int i=0;i<n;i++)
            tasks[i].push_back(i);
        
        sort(tasks.begin() , tasks.end());
        
        long currTime = tasks[0][0];
        
        cout<<currTime<<endl;
        int ind = 0;
        priority_queue<pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>>> pq;
        
        while(ind < n || pq.size() > 0)
        {
            
            if(pq.size()==0)
                currTime = max(currTime , (long)tasks[ind][0]);
            
            
            while(ind < n && tasks[ind][0] <= currTime)
            {
                int time = tasks[ind][1];
                int index = tasks[ind][2];
                
                // CPU temp(time , index);
                pq.push({time , index});
                
                ind++;
            }
            
            int processTime = pq.top().first;
            int index = pq.top().second;
            pq.pop();
            
            currTime += processTime ;
            
            ans.push_back(index);
            
            
        }
        
        return ans;
    }
};