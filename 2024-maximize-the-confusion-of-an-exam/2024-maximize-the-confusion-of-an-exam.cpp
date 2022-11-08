class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        
        
        int n = answerKey.length() , prev = 0 , tCnt = 0 , fCnt = 0 , maxLen = 0;
        
        
        for(int i=0;i<n;i++)
        {
            if(answerKey[i] == 'T')
                tCnt++;
            
            while(tCnt > k)
            {
                if(answerKey[prev] == 'T')
                    tCnt--;
                prev++;
            }
            
            maxLen = max(maxLen , (i-prev+1));
        }
        
        
        prev = 0;
        
        for(int i=0;i<n;i++)
        {
            if(answerKey[i] == 'F')
                fCnt++;
            
            while(fCnt > k)
            {
                if(answerKey[prev] == 'F')
                    fCnt--;
                prev++;
            }
            
            // cout<<i<<" "<<prev<<endl;
            maxLen = max(maxLen , (i-prev+1));
        }
        
        // cout<<endl;
        
        
        return maxLen;
        
    }
};