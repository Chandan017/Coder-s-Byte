class Solution {
public:
    
    pair<int,int>  getMax(vector<int> &nums)
    {
        map<int,int> mpp;
        
        for(auto it:nums)
            mpp[it]++;
        
        
        int val=0 , freq=0;
        for(auto it:mpp)
        {
            if(it.second > freq)
            {
                val=it.first;
                freq=it.second;
            }
        }
        
        return {val,freq};
    }
    
    int solve(vector<int> &nums1 , vector<int> &nums2 , int val)
    {
        int cnt=0;
        for(int i=0;i<nums1.size();i++)
        {
            if(nums1[i]!=val)
            {
                if(nums2[i]==val)
                    cnt++;
                else
                {
                    cnt=-1;
                    break;
                }
            }
        }
        
        return cnt;
    }
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        
        
        pair<int,int> maxTop=getMax(tops);
        pair<int,int> maxBottom=getMax(bottoms);
        
        int topCnt=solve(tops,bottoms , maxTop.first);
        int bottomCnt=solve(bottoms , tops , maxBottom.first);
        
        if(topCnt==-1)
            return bottomCnt;
        if(bottomCnt==-1)
            return topCnt;
        
        return min(topCnt , bottomCnt);
        
        
    }
};