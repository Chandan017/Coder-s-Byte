class Solution {
public:
    string multiply(string num1, string num2) {
        
        
        int n1=num1.size() , n2=num2.size();
        
        if(num1=="0" || num2=="0")
            return "0";
        
        vector<int> prod(n1+n2 , 0);
        
        for(int i=n1-1;i>=0;i--)
        {
            for(int j=n2-1;j>=0;j--)
            {
                prod[i+j+1] += (num1[i]-'0') * (num2[j]-'0');
                
                prod[i+j] += prod[i+j+1]/10;
                
                prod[i+j+1] = prod[i+j+1]%10;
            }
        }
        
        string ans="";
        
        int i=0;
        while(i<prod.size() && prod[i]==0)
            i++;
        
        for(;i<prod.size();i++)
            ans+=(prod[i]+'0');
        
        return ans;
    }
};