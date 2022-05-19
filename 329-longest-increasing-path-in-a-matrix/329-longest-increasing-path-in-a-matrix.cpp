class Solution {
public:
    
    
int moves[4][2] = { {-1,0},{1,0},{0,-1},{0,1} };
vector<vector<int> > dp; 
int maxPath, n, m;
    
int solve(vector<vector<int>>& mat, int i, int j)
{
	if(dp[i][j]) return dp[i][j]; 
	dp[i][j] = 1;  
	
	for(int k = 0; k < 4; k++){ 
		int new_i = i + moves[k][0], new_j = j + moves[k][1];
	
        
		if(new_i < 0 || new_j < 0 || new_i >= n || new_j >= m || mat[new_i][new_j] <= mat[i][j]) continue;
		
        
		dp[i][j] = max(dp[i][j], 1 + solve(mat, new_i, new_j));
	}         
	return dp[i][j];
}
   int longestIncreasingPath(vector<vector<int>>& matrix) {
	maxPath = 0, n = size(matrix), m = size(matrix[0]);
	dp.resize(n, vector<int>(m));
	
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			maxPath = max(maxPath, solve(matrix, i, j));            
	return maxPath;
}

};