class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        
        vector<int> ans;
        int n=matrix.size() , m=matrix[0].size();
        
        int left=0 , right=m-1 , top=0 , bottom=n-1;
        int dir=1;
        while(ans.size()!=n*m)
        {
            if(dir==1)
            {
                for(int i=left; i<=right; i++)
                    ans.push_back(matrix[top][i]);
                top++;
                dir=2;
            }
            
            else if(dir==2)
            {
                for(int i=top;i<=bottom;i++)
                    ans.push_back(matrix[i][right]);
                right--;
                dir=3;
            }
            
            else if(dir==3)
            {
                for(int i=right; i>=left;i--)
                    ans.push_back(matrix[bottom][i]);
                bottom--;
                dir=4;
            }
            
            else if(dir==4)
            {
                for(int i=bottom; i>=top;i--)
                    ans.push_back(matrix[i][left]);
                left++;
                dir=1;
            }
                        
        }
        
        return ans;
        
    }
};