//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    pair<int,int> endPoints(vector<vector<int>> matrix, int R, int C){
        //code here
        
        int r = 0 , c = 0;
        
        int dx[] = {-1,0,1,0};
        int dy[] = {0,1,0,-1};
        int dir = 1;
        while(r<R && c<C && r>=0 && c>=0)
        {
            if(matrix[r][c] == 0)
            {
                
                r += dx[dir%4];
                c += dy[dir%4];
            }
            else
            {
                matrix[r][c] = 0;
                dir++;
            }
        }
        
        r -= dx[dir%4];
        c -= dy[dir%4];
        
        return {r,c};
        
    }
};

//{ Driver Code Starts.


int main()
{
    int tc;
	scanf("%d", &tc);
	while(tc--){
		int row, col;
		scanf("%d", &row);
		scanf("%d", &col);
		vector<vector<int>> matrix(row , vector<int> (col));
	 
		for(int i = 0; i < row; i++){
			for(int j = 0; j < col; j++){
			    cin>>matrix[i][j];
			}
		}
		Solution obj;
		pair<int,int> p = obj.endPoints(matrix, row, col);
		
		cout << "(" << p.first << ", " << p.second << ")" << endl;
	}
	return 0;
}
// } Driver Code Ends