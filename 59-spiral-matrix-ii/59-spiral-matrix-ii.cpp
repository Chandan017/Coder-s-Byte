class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        
        vector<vector<int>> ans(n,vector<int> (n,0));
        
        int left=0,right=n-1 , top=0 , bottom=n-1;
        
        int direction=1;
        int val=1;
        
        while(val<=n*n)
        {
            if(direction==1)
            {
                for(int i=left;i<=right;i++)
                {
                    ans[top][i]=val;
                    val++;
                }
                
                direction=2;
                top++;
            }
            else if(direction==2)
            {
                
                for(int i=top;i<=bottom;i++)
                {
                    ans[i][right]=val;
                    val++;
                }
                
                direction=3;
                right--;
            }
            else if(direction==3)
            {
                
                for(int i=right;i>=left;i--)
                {
                    ans[bottom][i]=val;
                    val++;
                }
                
                direction=4;
                bottom--;
            }
            else if(direction==4)
            {
                
                for(int i=bottom;i>=top;i--)
                {
                    ans[i][left]=val;
                    val++;
                }
                
                direction=1;
                left++;
            }
        }
        
        return ans;
        
    }
};