//Solution 1 : Top-Down Approach

class Solution {
public:
    int minPathSum(int row, int col, vector<vector<int>>& matrix,int n, vector<vector<int>>& dp){
        if(row == n-1) return matrix[row][col];

        int left = INT_MAX;
        if(col-1 >= 0){
            left = minPathSum(row+1, col-1, matrix, n, dp);
        }
        
        
        int down = minPathSum(row+1, col, matrix, n, dp);

        int right = INT_MAX;
        if(col+1 < n){
            right = minPathSum(row+1, col+1, matrix, n, dp);
        }
        
        return dp[row][col] = min(left, min(down, right)) + matrix[row][col];
    }

    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));

        int result = INT_MAX;

        for(int col = 0; col < n; col++){
            result = min(result, minPathSum(0, col, matrix, n, dp));
        }
        return result;
    }
};

//Solution 2 : Bottom-Up

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> t(n, vector<int>(n));

        for(int col = 0; col <n; col++){
            t[n-1][col] = matrix[n-1][col];
        }
        for(int i = n-2; i>=0; i--){
            for(int j = 0; j<n; j++){
                t[i][j] = matrix[i][j] + min(t[i+1][max(j-1, 0)], min(t[i+1][j], t[i+1][min(j+1, n-1)]));
            }
        }

        return *min_element(begin(t[0]), end(t[0]));
    }
};