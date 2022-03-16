class Solution {
public:
    
    vector<vector<int>> ans;
    
    void get(int n , int k , vector<int> &temp,int start)
    {
        if(temp.size()==k)
        {
            ans.push_back(temp);
            return ;
        }
        
        for(;start<=n;start++)
        {
            temp.push_back(start);
            get(n,k,temp,start+1);
            
            temp.pop_back();
        }
        
        return ;
    }
    vector<vector<int>> combine(int n, int k) {
        
        
        vector<int> temp;
        
        get(n,k,temp,1);
        
        return ans;
    }
};