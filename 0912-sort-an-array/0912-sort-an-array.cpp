class Solution {
public:
    
    void merge(vector<int> &nums , int start , int mid , int end)
    {
        if(start >= end)
            return ;
        
        int i = start , j = mid+1 , k = 0 , len = end-start+1;
        vector<int> res(len , 0);
        
        while(i <= mid && j <= end)
        {
            if(nums[i] <= nums[j])
            {
                res[k] = nums[i];
                i++;
            }
            else
            {
                res[k] = nums[j];
                j++;
            }
            k++;
        }
        
        while(i <= mid)
        {
            res[k] = nums[i];
            i++;
            k++;
        }
        
        while(j <= end)
        {
            res[k] = nums[j];
            j++;
            k++;
        }
        
        for(k=0;k<len;k++)
        {
            nums[k+start] = res[k];
        }
        
        
        return ;
    }
    
    void mergeSort(vector<int> &nums , int start , int end)
    {
        if(start < end)
        {
            int mid = start + (end-start)/2;
            
            mergeSort(nums , start , mid);
            mergeSort(nums , mid+1 , end);
            
            merge(nums , start , mid , end);
            
            return ;
        }
        return ;
    }
    vector<int> sortArray(vector<int>& nums) {
        
        mergeSort(nums , 0 , nums.size()-1);
        
        return nums;
        
    }
};