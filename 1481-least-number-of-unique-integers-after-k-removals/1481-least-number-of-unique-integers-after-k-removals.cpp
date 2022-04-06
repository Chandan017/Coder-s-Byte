class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        
        priority_queue<pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>>> pq;
        
        map<int,int> mpp;
        for(auto &it:arr)
            mpp[it]++;
        
        for(auto &it:mpp)
        {
            pq.push({it.second , it.first});
        }
        
        while(pq.size() > 0 && k>0)
        {
            int times = pq.top().first;
            int val = pq.top().second;
            pq.pop();
            
            if(times <= k)
            {
                int temp=times;
                times -= k;
                k-=temp;
            }
            else
            {
                int temp=times;
                times -= k;
                k-= (temp - times);
            }
            
            if(times > 0)
                pq.push({times , val});
        }
        
        return pq.size();
    }
};