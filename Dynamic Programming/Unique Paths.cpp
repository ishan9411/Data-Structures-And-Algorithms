//Leetcode : 62. Unique Paths
//Solution 1 : Recursion + Memoization

class Solution {
public:
    //this function returns the no. of paths from index (i, j) to (m-1, n-1)
    int paths(int i, int j, int m, int n, vector<vector<int>>& dp){
        if(i >= m ||j >= n){
            return 0;
        }
        if(i == m-1 && j == n-1){
            return 1;
        }
        if(dp[i][j] != -1) return dp[i][j];

        //down  
        int d = paths(i+1, j, m, n, dp);

        //right
        int r = paths(i, j+1, m, n, dp);

        return dp[i][j] = d+r;
    }

    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return paths(0, 0, m, n, dp);
    }
};

//Solutiion 2 : Bottom-Up

class Solution {
public:

    int uniquePaths(int m, int n) {
        vector<vector<int>> t(m, vector<int>(n, -1)); //t[i][j] represents no. of paths from (i, j) to (0,0)

        for(int i = 0; i<m; i++){
            t[i][0] = 1;
        }
        for(int i = 0; i<n; i++){
            t[0][i] = 1;
        }
        for(int i = 1; i<m; i++){
            for(int j = 1; j<n; j++){
                t[i][j] = t[i-1][j] + t[i][j-1];
            }
        }

        return t[m-1][n-1];
    }
};