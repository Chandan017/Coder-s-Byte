class Solution {
public:
    
    pair<int,int>  getMax(vector<int> &tops , vector<int> &bottoms)
    {
        int mpp1[6]={0};
        int mpp2[6]={0};
        
        for(int i=0;i<tops.size();i++)
        {
            mpp1[tops[i]-1]++;
            mpp2[bottoms[i]-1]++;
        }
        
        int val1=0 , val2=0 , freq1=0 , freq2=0;
        for(int i=0;i<6;i++)
        {
            if(mpp1[i] > freq1)
            {
                val1=i;
                freq1=mpp1[i];
            }
            
            if(mpp2[i] > freq2)
            {
                val2=i;
                freq2=mpp2[i];
            }
        }
        
        return {val1+1 , val2+1};
    }
    
    int solve(vector<int> &tops , vector<int> &bottoms , int val1 , int val2)
    {
        
        int cnt1=0 , cnt2=0;
        
        for(int i=0;i<tops.size();i++)
        {
            if(cnt1!=-1 && tops[i]!=val1)
            {
                if(bottoms[i]==val1)
                    cnt1++;
                else
                    cnt1=-1;
            }
            
            if(cnt2!=-1 && bottoms[i]!=val2)
            {
                if(tops[i]==val2)
                    cnt2++;
                else
                    cnt2=-1;
            }
        }
        
        
        if(cnt1==-1)
            return cnt2;
        if(cnt2==-1)
            return cnt1;
        return min(cnt1 , cnt2);
        
    }
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        
        
        pair<int,int> maxVals=getMax(tops , bottoms);
       
        int ans=solve(tops , bottoms , maxVals.first , maxVals.second);
        
        return ans;
        
    }
};