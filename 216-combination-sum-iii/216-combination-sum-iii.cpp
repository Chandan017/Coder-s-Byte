class Solution {
public:
    
    vector<vector<int>> ans;
    
    
    void get(int k , int n , vector<int> temp , int currVal)
    {
        if(n<0 || temp.size() > k)
            return ;
        if(n==0 && temp.size()==k)
        {
            ans.push_back(temp);
            return ;
        }
        
        for(int i = currVal ; i<=9;i++)
        {
            temp.push_back(i);
            n-=i;
    
            
            get(k,n,temp , i+1);
            
            temp.pop_back();
            n+=i;
            
            
            
        }
        
        return ;
    }
    
    vector<vector<int>> combinationSum3(int k, int n) {
        
       
        vector<int> temp;
        get(k,n , temp , 1);
        
        return ans;
    }
};