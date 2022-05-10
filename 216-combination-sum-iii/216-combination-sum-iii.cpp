class Solution {
public:
    vector<vector<int>> ans;
    
    void getAll(int len, int totalVal , vector<int> &temp , int currVal)
    {
        if(len<0 || totalVal<0)
            return ;
        if(len==0 && totalVal==0)
        {
            ans.push_back(temp);
            return ;
        }
        
        for(int i=currVal;i<=9;i++)
        {
            temp.push_back(i);
            
            
            getAll(len-1 , totalVal-i , temp , i+1);
            
            temp.pop_back();
            
        }
        return ;
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        
        vector<int> temp;
        
        getAll(k,n,temp,1);
        
        return ans;
        
    }
};