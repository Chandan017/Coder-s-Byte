class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        
        
        
        priority_queue<int , vector<int> , greater<int>> left , right;
        
        int n = costs.size();
        vector<bool> vis(n , false);
        
        int l= 0 , r = n-1;
        
        while(l<candidates)
        {
            left.push(costs[l]);
            vis[l] = true;
            l++;
        }
        
        while(r >= n-candidates && !vis[r])
        {
            right.push(costs[r]);
            vis[r] = true;
            r--;
            
        }
        
        long long sum = 0;
        // cout<<l<<" "<<r<<endl;
        while(k--)
        {
            long long leftTop = INT_MAX , rightTop = INT_MAX;
            
            if(left.size())
            {
                leftTop = left.top();
            }
            
            if(right.size())
            {
                rightTop = right.top();
            }
            
            if(leftTop <= rightTop)
            {
                sum += leftTop;
                left.pop();
                if(l<n && !vis[l])
                {
                    left.push(costs[l]);
                    vis[l] = true;
                    l++;
                }
            }
            else
            {
                sum += rightTop;
                right.pop();
                
                
                if(r>=0 && !vis[r])
                {
                    vis[r] = true;
                    right.push(costs[r]);
                    r--;
                }
            }
            
            // cout<<sum<<" ";
            
        }
        
        // cout<<endl;
        
        
        
        return sum;
        
        
        
    }
};