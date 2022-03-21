class Solution {
public:
    vector<int> partitionLabels(string s) {
        
        vector<int> ans;
        
        int maxRange[26]={0};
        int n=s.length();
        for(int i=0;i<n;i++)
        {
            maxRange[s[i]-'a']=i;
        }
        
        for(auto it:maxRange)
            cout<<it<<" ";
        cout<<endl;
        
        int j=0;
        int prev=0;
        for(int i=0;i<n;i++)
        {
            j=max(j,maxRange[s[i]-'a']);
            
            if(i==j)
            {
                ans.push_back(j-prev+1);
                prev=i+1;
            }
        }
        
        return ans;
        
    }
};