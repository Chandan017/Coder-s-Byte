class Solution {
public:
    int largestInteger(int num) {
        
        string s = to_string(num);
        
        string even="" , odd="";
        bool hasEven = false;
        for(int i=0;i<s.length();i++)
        {
            int n = s[i]-'0';
            if(i==0 && n%2==0)
                hasEven = true;
                
            if(n%2==0)
            {
                even += (n+'0');
            }
            else
                odd += (n+'0');
        }
        
        sort(even.begin() , even.end() , greater<int>());
        sort(odd.begin() , odd.end() , greater<char>());
        
        string ans = "";
        int  i=0, j=0;
        for(auto it:s)
        {
            int n = it - '0';
            
            if(n%2==0)
            {
                ans += even[i++];
            }
            else
                ans += odd[j++];
        }
        
        return stoi(ans);
        
    }
};