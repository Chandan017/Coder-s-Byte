class Solution {
public:
    
    long long get(vector<vector<int>> &questions , int currInd , int n , vector<long long> &dp)
    {
        if(currInd >=n)
            return 0;
        
        if(dp[currInd] != -1)
            return dp[currInd];
        
        long long solveIt = questions[currInd][0] + get(questions , currInd+questions[currInd][1]+1 , n , dp);
        
        long long notSolveIt = get(questions , currInd+1 , n , dp);
        
        return dp[currInd] = max(solveIt , notSolveIt);
    }
    long long mostPoints(vector<vector<int>>& questions) {
     
        
        int n=questions.size();
        vector<long long> dp(n+1 , -1);
        long long maxPoints = get(questions , 0 , n , dp);
        
        return maxPoints;
    }
};