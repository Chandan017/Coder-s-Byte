class Solution {
public:
    long long numberOfWays(string s) {
        
        int n=s.length();
        
        vector<long long> leftZero(n , 0);
        vector<long long> rightZero(n , 0);
        vector<long long> leftOne(n , 0);
        vector<long long> rightOne(n , 0);
        
        long long cntOneLeft=0, cntOneRight=0 , cntZeroLeft=0 , cntZeroRight=0;
        
        for(int i=0;i<n;i++)
        {
            leftZero[i] = cntZeroLeft;
            leftOne[i] =cntOneLeft;
            
            rightZero[n-i-1] = cntZeroRight;
            rightOne[n-i-1] = cntOneRight;
            
            if(s[i]=='0')
                cntZeroLeft++;
            else
                cntOneLeft++;
            
            if(s[n-i-1]=='0')
                cntZeroRight++;
            else
                cntOneRight++;
        }
        
        long long cnt=0;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='0')
            {
                cnt += leftOne[i]*rightOne[i];
            }
            else
            {
                cnt += leftZero[i]*rightZero[i];
            }
        }
        
        return cnt;
        
    }
};