class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        
        priority_queue<pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>>> pq;
        
        sort(arr.begin() , arr.end());
        int n=arr.size();
        for(int i=0;i<n;i++)
        {
            int cnt=1;
            while(i<n-1 && arr[i]==arr[i+1])
            {
                cnt++;
                i++;
            }
            
            pq.push({cnt , arr[i]});
            
        }
    
        
        while(pq.size() > 0 && k>0)
        {
            int times = pq.top().first;
            int val = pq.top().second;
            pq.pop();
            
            int temp=times;
            times -= k;
            
            if(times <= k)
                k-=temp;
            
            else
                k-= (temp - times);
            
            if(times > 0)
                pq.push({times , val});
        }
        
        return pq.size();
    }
};