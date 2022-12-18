class Solution {
public:
    int similarPairs(vector<string>& words) {
        
        vector<set<char>> temp;
        
        for(auto word:words)
        {
            set<char> st;
            
            for(auto j:word)
                st.insert(j);
            temp.push_back(st);
        }
        
        int cnt = 0;
        
        for(int i=0;i<temp.size()-1;i++)
        {
            for(int j=i+1;j<temp.size();j++)
            {
                if(temp[i] == temp[j])
                    cnt++;
            }
        }
        
        return cnt;
    }
};