class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        
        set<string> st;
        
        for(auto it:nums)
            st.insert(it);
        
        int n = nums[0].length();
        
        string res = "";
        
        while(n--)
            res += '0';
        
        n = nums[0].length();
        int cnt = 0;
        int ind = 0;
        while(true)
        {
            if(st.find(res) == st.end())
                break;
            else
            {
                if(ind==n)
                {
                    res[cnt] = '1';
                    cnt++;
                    ind = cnt;
                }
                else
                {
                    if(ind==cnt)
                    {
                        res[ind] ='1';
                        ind++;
                    }
                    else
                    {
                        res[ind-1] = '0';
                        res[ind] = '1';
                        ind++;
                    }
                }
            }
        }
        
        return res;
        
    }
};