//Solution 1 : Bottom-Up Approach

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> dp(m, vector<int>(n, -1));
        dp[0][0] = grid[0][0];

        for(int i = 1; i<m; i++){
            dp[i][0] = dp[i-1][0] + grid[i][0];
        }
        for(int i = 1; i<n; i++){
            dp[0][i] = dp[0][i-1] + grid[0][i];
        }

        for(int i = 1; i<m; i++){
            for(int j = 1; j<n; j++){
                dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + grid[i][j];
            }
        }
        return dp[m-1][n-1];
    }
};

//Solution 2 : Top-Down Approach

class Solution {
public:
    int minSum(int i, int j, int m, int n, vector<vector<int>>& grid, vector<vector<int>>& dp){
        if(i == m-1 && j == n-1) return grid[m-1][n-1];
        
        if(dp[i][j] != -1) return dp[i][j];

        int down = INT_MAX;
        if(i+1 < m){
            down   = minSum(i+1, j, m, n, grid, dp);
        }
        
        int right = INT_MAX;
        if(j+1 < n){
            right  = minSum(i, j+1, m, n, grid, dp);
        }
        
        return dp[i][j] = min(down, right) + grid[i][j];
    }

    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> dp(m, vector<int>(n, -1));

        return minSum(0, 0, m, n, grid, dp);
    }
};