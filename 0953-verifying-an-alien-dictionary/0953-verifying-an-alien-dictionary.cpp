class Solution {
public:
    unordered_map<char,int> mpp;
    
    bool notValid(string &a , string &b)
    {
        for(int i=0;i<min(a.length() , b.length());i++)
        {
            // cout<<mpp[a[i]]<<" "<<mpp[b[i]]<<"  ";
            if(mpp[a[i]] < mpp[b[i]])
                return false;
            if(mpp[a[i]] > mpp[b[i]])
                return true;
        }
        
        if(a.length() > b.length())
            return true;
        return false;
    }
    bool isAlienSorted(vector<string>& words, string order) {
        
        for(int i=0;i<order.length();i++)
            mpp[order[i]] = i;
        
        int n = words.size();
        // cout<<"Starts"<<endl;
        for(int i=0;i<n-1;i++)
        {
            string a = words[i] , b = words[i+1];
            
            if(notValid(a , b))
                return false;
            // cout<<endl;
        }
        
        return true;
    }
};