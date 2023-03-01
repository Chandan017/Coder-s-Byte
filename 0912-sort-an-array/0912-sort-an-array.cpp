class Solution {
public:
    
    void mergeSort(vector<int> &nums , int start, int end)
    {
        if(start >= end)
            return ;
        int mid = (start+end)/2;
        mergeSort(nums , start , mid);
        mergeSort(nums , mid+1 , end);
        
        merge(nums , start , mid , end);
        
        return ;
    }
    
    void merge(vector<int> &nums , int start , int mid , int end)
    {
        int i = start , j = mid+1;
        vector<int> res;
        while(i<=mid && j<=end)
        {
            if(nums[i]<=nums[j])
            {
                res.push_back(nums[i]);
                i++;
            }
            else
            {
                res.push_back(nums[j]);
                j++;
            }
        }
        
        while(i<=mid)
        {
            res.push_back(nums[i]);
            i++;
        }
        
        while(j<=end)
        {
            res.push_back(nums[j]);
            j++;
        }
        
        i = start;
        for(auto it:res)
        {
            nums[i] = it;
            i++;
        }
        return ;
    }
    vector<int> sortArray(vector<int>& nums) {
        
        int n = nums.size();
        mergeSort(nums , 0 , n-1);
        
        return nums;
        
    }
};