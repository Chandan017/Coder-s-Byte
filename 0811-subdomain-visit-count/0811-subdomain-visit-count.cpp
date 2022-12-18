class Solution {
public:
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        
        
        map<string,int> mpp;
        
        
        for(auto s:cpdomains)
        {
            
            int times = 0;
            int n = s.length() , start = 0;
            while(start<n && s[start] != ' ')
            {
                times = times*10 + (s[start]-'0');
                start++;
            }
            
            string curr = "";
            int i = n-1;
            
            while(i>start)
            {
                while(i> start && s[i] != '.')
                {
                    curr += s[i];
                    i--;
                }
                string temp = curr;
                reverse(temp.begin() , temp.end());
                mpp[temp] += times;
                i--;
                // cout<<temp<<" ";
                curr += '.';
            }

            
            // cout<<times<<" ";
        }
        
        // cout<<endl;
        vector<string> res;
        
        
        for(auto it:mpp)
        {
            string curr = to_string(it.second) +" " + it.first;
            
            res.push_back(curr);
        }
        
        return res;
        
    }
};