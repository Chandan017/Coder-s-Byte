class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num1, int k) {
        
        vector<int> num2;
        
        while(k)
        {
            num2.push_back(k%10);
            k /= 10;
        }
        reverse(num1.begin() , num1.end());
        
        int n = num1.size() , m = num2.size() , carry = 0 , i = 0 , j = 0;
        vector<int> res;
        int cnt = 0;

        while(i<n || j<m || carry>0)
        {            
            int val = carry;
            if(i<n)
            {
                val += num1[i];
                i++;
            }
            
            if(j<m)
            {
                val += num2[j];
                j++;
            }
            
            res.push_back(val%10);
            
            carry = val/10;
        }
        
        reverse(res.begin() , res.end());
        return res;
        
    }
};