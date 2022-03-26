class Solution {
    
private:
    
    vector<int> getNSL(vector<int> &heights)
    {
        stack<pair<int,int>> st;
        int  n=heights.size();
        vector<int> nsl(n);
        
        for(int i=0;i<n;i++)
        {
            while(st.size()>0 && st.top().first>=heights[i])
                st.pop();
            
            if(st.size()==0)
                nsl[i]=-1;
            else
                nsl[i]=st.top().second;
            
            st.push({heights[i] , i});
        }
        
        return nsl;
    }
    
    vector<int> getNSR(vector<int> &heights)
    {
        int n=heights.size();
        stack<pair<int,int>> st;
        vector<int> nsr(n);
        
        for(int i=n-1;i>=0;i--)
        {
            while(st.size()>0 && st.top().first >=heights[i])
                st.pop();
            if(st.size()==0)
                nsr[i]=n;
            else
                nsr[i]=st.top().second;
            st.push({heights[i] , i});
        }
        return nsr;
    }
    int getMAH(vector<int> &heights)
    {
        vector<int> nsl=getNSL(heights);
        vector<int> nsr=getNSR(heights);
        int maxArea=0;
        for(int i=0;i<heights.size();i++)
        {
            int width=nsr[i]-nsl[i]-1;
            
            int area=heights[i] * width;
            
            maxArea=max(maxArea , area);
        }
        
        return maxArea;
    }
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        
        int n=matrix.size();
        int m=matrix[0].size();
        vector<int> heights(m,0);
        for(auto it:heights)
            cout<<it<<" ";
        cout<<endl<<endl;
        int maxArea=0;
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(matrix[i][j]=='1')
                    heights[j]++;
                else
                    heights[j]=0;
            }
            for(auto it:heights)
                cout<<it<<" ";
            cout<<endl;
            
            int currMAH=getMAH(heights);
            
            maxArea=max(maxArea , currMAH);
        }
        
        return maxArea;
        
    }
};