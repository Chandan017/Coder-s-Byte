class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        
        priority_queue<pair<int,int>> pq;
        
        int n=mat.size();
        int m=mat[0].size();
        
        for(int i=0;i<n;i++)
        {
            int soldiers=0;
            for(int j=0;j<m;j++)
            {
                if(mat[i][j]==1)
                    soldiers++;
            }
            
            pq.push({soldiers , i });
            if(pq.size() >k)
                pq.pop();
        }
        
        vector<int> ans(k);
        int i=k-1;
        while(pq.size())
        {
            ans[i--]=pq.top().second;
            pq.pop();
        }
        
        return ans;
        
        
    }
};