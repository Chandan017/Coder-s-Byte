class Solution {

private:
    
    vector<int> getNSR(vector<int> &heights)
    {
        stack<pair<int,int>> st;
        int n=heights.size();
        vector<int> nsr(n);
        for(int i=n-1;i>=0;i--)
        {
            while(st.size()>0 && st.top().first>=heights[i])
                st.pop();
            
            if(st.size()==0)
                nsr[i]=n;
            else
                nsr[i]=st.top().second;
            
            st.push({heights[i] , i});
        }
        
        return nsr;
    }
    
    
    vector<int> getNSL(vector<int> &heights)
    {
        stack<pair<int,int>> st;
        int n=heights.size();
        vector<int> nsl(n);
        
        for(int i=0;i<n;i++)
        {
            while(st.size() > 0 && st.top().first >=heights[i])
                st.pop();
            
            if(st.size()==0)
                nsl[i]=-1;
            else
                nsl[i]=st.top().second;
            st.push({heights[i] , i});
        }
        
        return nsl;
    }
public:
    
    int largestRectangleArea(vector<int>& heights) {
        
        vector<int> nsl=getNSL(heights);
        vector<int> nsr=getNSR(heights);
        int maxArea=0;
        for(int i=0;i<heights.size();i++)
        {
            int width=nsr[i]-nsl[i]-1;
            
            int area=width * heights[i];
            
            maxArea=max(maxArea , area);
        }
        
        return maxArea;
        
    }
};