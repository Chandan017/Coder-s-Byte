class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        
        map<int,int> mpp;
        
        for(int i=0;i<nums2.size();i++)
            mpp[nums2[i]]=i;
        
        vector<int> ans;
        
        
        for(int i=0;i<nums1.size();i++)
        {
            int temp=-1;
            
            int ind=mpp[nums1[i]];
            
            for(int j=ind+1;j<nums2.size();j++)
            {
                if(nums2[j] > nums1[i])
                {
                    temp=nums2[j];
                    break;
                }
            }
            
            ans.push_back(temp);
        }
        
        return ans;
        
    }
};