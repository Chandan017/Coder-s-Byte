class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        
        int n = code.size();
        vector<int> decoded(n);
        int sum = 0;
        
        if(k<0)
        {
            k = abs(k);
            
            for(int i=(n-k);i<(2*n);i++)
            {
                if(i<n)
                {
                    sum += code[i];
                }
                else
                {
                    decoded[i%n] = sum;
                    sum -= code[(i-k)%n];
                    sum += code[i%n];
                }
            }
        }
        else if(k>0)
        {            
            
            for(int i=n-1+k;i>=0;i--)
            {
                if(i>n-1)
                {
                    sum += code[i%n];
                }
                else
                {
                    decoded[i] = sum;
                    sum -= code[(i+k)%n];
                    sum += code[i];
                }
            }
        }
        else
        {
            for(int i=0;i<n;i++)
                decoded[i] = 0;
            
        }
        
        return decoded;
        
    }
};