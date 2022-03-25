class Solution {
public:
    
    static bool comp(vector<int> &a , vector<int> &b)
    {
        if(a[0]-a[1] < b[0]-b[1])
            return true;
        
        return false;
        
    }
    int twoCitySchedCost(vector<vector<int>>& costs) {
        
        int totalPeople=costs.size();
        
        sort(costs.begin() , costs.end() , comp);
        long long totalCost=0;
        int n=totalPeople/2;
        for(int i=0;i<costs.size();i++)
        {
            if(i<n)
                totalCost+=costs[i][0];
            else
                totalCost+=costs[i][1];
            
           // cout<<costs[i][0]<<"->"<<costs[i][1]<<"  ";
            
        }
        

        
        return totalCost;
    }
};