class Solution {
public:
    vector<int> getCount(int n)
    {
        vector<int> res(10 , 0);
        
        while(n)
        {
            int val = n%10;
            res[val]++;
            n /= 10;
        }
        return res;
    }
    bool reorderedPowerOf2(int n) {
        
        vector<int> nCnt = getCount(n);
        
        for(int i=0;i<31;i++)
        {
            vector<int> currCnt = getCount(pow(2 , i));
            
            if(currCnt == nCnt)
                return true;
        }
        
        return false;
        
    }
};