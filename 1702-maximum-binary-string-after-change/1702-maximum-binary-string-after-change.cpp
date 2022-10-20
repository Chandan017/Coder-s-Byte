class Solution {
public:
    string maximumBinaryString(string bin) {
        
        int n = bin.length();
        int i= 0 , ind = n-1;
        
        while(i<n && bin[i]=='1')
            i++;
        
        ind = i;
        int cnt = 0;
        
        while(i<n)
        {
            if(bin[i] == '0')
                cnt++;
            i++;
        }
        while(ind<n)
        {
            if(cnt == 1)
                bin[ind] = '0';
            else
                bin[ind] = '1';
            cnt--;
            ind++;
            
        }
        
        return bin;
        
    }
};