//Leetcode : 63. Unique Paths II
//Solution 1 : Recursion + Memoization

class Solution {
public:
    int noOfPaths(int i, int j, int m, int n, vector<vector<int>>& obstacleGrid, vector<vector<int>>& dp){
        if(i >= m || j >= n){
            return 0;
        }
        if(obstacleGrid[i][j] == 1){
            return 0;
        }
        if(i == m-1 &&  j == n-1){
            return 1;
        }
        if(dp[i][j] != -1) return dp[i][j];

        int down = noOfPaths(i+1, j, m, n, obstacleGrid, dp);

        int right = noOfPaths(i, j+1, m, n, obstacleGrid, dp);

        return dp[i][j] = down+right;
    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));

        return noOfPaths(0, 0, m, n, obstacleGrid, dp);
    }
};

//Solution 2 : Bottom-Up

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        
        vector<vector<int>> t(m, vector<int>(n, 0));

        for(int i = 0; i<m; i++){
            if(obstacleGrid[i][0] == 1){
                break;
            }
            t[i][0] = 1;
        }
        for(int i = 0; i<n; i++){
            if(obstacleGrid[0][i] == 1){
                break;
            }
            t[0][i] = 1;
        }
        
        for(int i = 1; i<m; i++){
            for(int j = 1; j<n; j++){
                if(obstacleGrid[i][j] == 1){
                    continue;
                }
                t[i][j] = t[i-1][j] + t[i][j-1];
            }
        }

        return t[m-1][n-1];
    }
};
