class Solution {
public:
    vector<int> partitionLabels(string s) {
        
        int maxReach[26]={0};
        vector<int> ans;
        
        for(int i=0;i<s.length();i++)
        {
            maxReach[s[i]-'a']=i;
        }
        int j=0;
        for(int i=0;i<s.length();i++)
        {
            j=maxReach[s[i]-'a'];

            int prev=i;
            cout<<prev<<endl;
            while(i<j)
            {
                if(maxReach[s[i]-'a'] <=j)
                    i++;
                else
                {
                    j=maxReach[s[i]-'a'];
                    i++;
                }
            }
            
            if(i==j)
            {
                ans.push_back(j+1-prev);
            }
                
            
            
        }
        
        
        
        return ans;
        
        
        
    }
};