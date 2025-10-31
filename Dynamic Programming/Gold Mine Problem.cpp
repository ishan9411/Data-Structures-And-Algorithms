//GFG : Gold Mine Problem
//Solution 1 : Recursion + Memoization

class Solution {
  public:
    vector<vector<int>> dp;
  
    int maxGold(vector<vector<int>>& mat, int i, int j, int n){
        if(i < 0 || i>=n || j >= n){
            return 0;
        }
        
        if(dp[i][j] != -1) return dp[i][j];
        
        int upDia = mat[i][j] + maxGold(mat, i-1, j+1, n);
        int right = mat[i][j] + maxGold(mat, i, j+1, n);
        int downDia = mat[i][j] + maxGold(mat, i+1, j+1, n);
        
        return dp[i][j] = max(upDia, max(right, downDia));
    }
  
    int maxGold(vector<vector<int>>& mat) {
        // code here
        int n = mat.size();
        
        dp.assign(n, vector<int>(n, -1));
        int result = 0;
        for(int i = 0; i<n; i++){
            result = max(result, maxGold(mat, i, 0, n));
        }
        return result;
    }
};

//Solution 2 : Bottom-Up

class Solution {
  public:
    int maxGold(vector<vector<int>>& mat) {
        int n = mat.size();
        
        vector<vector<int>> t(n, vector<int>(n, -1));
        
        for(int i = 0; i<n; i++){
            t[i][n-1] = mat[i][n-1];
        }
        
        for(int col = n-2; col >= 0; col--){
            for(int row = 0; row<n; row++){
                int upDia = row-1 >= 0 ? t[row-1][col+1] : 0;
                int right = t[row][col+1];
                int downDia = row+1<n ? t[row+1][col+1] : 0;
                t[row][col] = max(upDia, max(right, downDia)) + mat[row][col];
            }
        }
        
        int result = 0;
        for(int i = 0; i<n; i++){
            result = max(result, t[i][0]);
        }
        return result;
    }
};