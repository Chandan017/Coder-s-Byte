class Solution {
public:
    int strStr(string haystack, string needle) {
        
        int needleLen = needle.length();
        int haystackLen = haystack.length();
        
        if(needleLen==0)
            return 0;
        
        for(int i=0;i<haystackLen;i++)
        {
            if(haystack[i] == needle[0])
            {
                int dupInd = i+1;
                bool flag = true;
                for(int j=1;j<needleLen;j++)
                {
                    if(needle[j] != haystack[dupInd])
                    {
                        flag = false;
                        break;
                    }
                    dupInd++;
                }
                
                if(flag)
                    return i;
                
                
            }
        }
        
        return -1;
        
    }
};