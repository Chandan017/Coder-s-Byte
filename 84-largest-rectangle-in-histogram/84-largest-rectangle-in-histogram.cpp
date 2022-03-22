class Solution {
public:
    
    vector<int> getNSL(vector<int> &heights)
    {
        vector<int> ans;
        stack<pair<int,int>> st;
        
        for(int i=0;i<heights.size();i++)
        {
            if(st.size()==0)
                ans.push_back(-1);
            else if(st.size()>0 && st.top().first<heights[i])
                ans.push_back(st.top().second);
            else if(st.size()>0 && st.top().first>=heights[i])
            {
                while(st.size()>0 && st.top().first>=heights[i])
                    st.pop();
                
                if(st.size()==0)
                    ans.push_back(-1);
                else
                    ans.push_back(st.top().second);
            }
            
            st.push({heights[i] , i});
        }
        
        return ans;
    }
    
    vector<int> getNSR(vector<int> &heights)
    {
        int n=heights.size();
        vector<int> ans(n,n);
        stack<pair<int,int>> st;
        
        for(int i=n-1;i>=0;i--)
        {
            if(st.size()==0)
                ans[i]=n;
            else if(st.size()>0 && st.top().first<heights[i])
                ans[i]=(st.top().second);
            else if(st.size()>0 && st.top().first>=heights[i])
            {
                while(st.size()>0 && st.top().first>=heights[i])
                    st.pop();
                
                if(st.size()==0)
                    ans[i]=(n);
                else
                    ans[i]=(st.top().second);
            }
            
            st.push({heights[i] , i});
        }
        
        
        
        return ans;
    }
    int largestRectangleArea(vector<int>& heights) {
        
       vector<int> nsl=getNSL(heights);
        vector<int> nsr=getNSR(heights);
        
        int maxi=0;
        
        int n=heights.size();
        
        for(int i=0;i<n;i++)
        {
            int l=nsr[i]-nsl[i]-1;
            
            int area=l*heights[i];
            
            maxi=max(maxi , area);
        }
        
        for(auto it:nsl)
            cout<<it<<" ";
        cout<<endl;
        for(auto it:nsr)
            cout<<it<<" ";
        cout<<endl;
        return maxi;
        
        
    }
};