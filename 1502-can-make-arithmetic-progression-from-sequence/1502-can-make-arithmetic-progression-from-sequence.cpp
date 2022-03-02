class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        
        sort(arr.begin() , arr.end());
        int diff=0;
        for(int i=1;i<arr.size();i++)
        {
            if(i==1)
                diff=arr[i]-arr[i-1];
            
            else
            {
                if(arr[i]-arr[i-1]!=diff)
                    return false;
            }
        }
        return true;
    }
};