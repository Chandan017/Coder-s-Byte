class Solution {
public:
    int minMaxDifference(int num) {
        
        int maxi = num , mini = num;
        string s = to_string(num);
        int i = 0 , n = s.length();
        
        while(i<n && s[i] == '9')
            i++;
        
        if(i<n)
        {
            int j = i+1;
            while(j<n)
            {
                if(s[j] == s[i])
                    s[j] = '9';
                j++;
            }
            
            s[i] = '9';
            
            maxi = stoi(s);
        }
        
        i = 0 ;
        s = to_string(num);
        
        while(i<n && s[i] == '0')
            i++;
        
        if(i<n)
        {
            int j = i+1;
            while(j<n)
            {
                if(s[j] == s[i])
                    s[j] = '0';
                j++;
            }
            
            s[i] = '0';
            
            mini = stoi(s);
        }
        
        cout<<maxi<<" "<<mini<<endl;
        
        return (maxi - mini);
        
    }
};