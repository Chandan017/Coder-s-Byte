class Solution {
public:
    int maxArea(int h, int w, vector<int>& hCuts, vector<int>& vCuts) {
        
        hCuts.push_back(0);
        vCuts.push_back(0);
        
        sort(hCuts.begin() , hCuts.end());
        sort(vCuts.begin() , vCuts.end());
        
        int hLen = hCuts.size() , vLen = vCuts.size();
        
        if(hCuts[hLen-1] !=h)
        {
            hCuts.push_back(h);
            hLen++;
        }
        
        if(vCuts[vLen-1] != w)
        {
            vCuts.push_back(w);
            vLen++;
        }
        
        long maxH  = 0 ,maxV = 0;
        
        for(int i=1;i<hLen;i++)
        {
            long curr =abs( hCuts[i] - hCuts[i-1]);
            
            maxH = max(maxH , curr);
        }
        
        for(int i=1;i<vLen;i++)
        {
            long curr = abs(vCuts[i] - vCuts[i-1]);
            maxV = max(maxV , curr);
        }
        int mod = 1e9 + 7;
        return (maxH*maxV)%mod;
        
    }
};