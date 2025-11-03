//Solution 1 : Recursion + Memoization

class Solution {
public:
    int lcs(string text1, string text2, int i, int j, vector<vector<int>>& dp){
        if(i >= text1.length() || j >= text2.length()){
            return 0;
        }
        if(dp[i][j] != -1) return dp[i][j];
        if(text1[i] == text2[j]){
            return dp[i][j] = lcs(text1, text2, i+1, j+1, dp) + 1;
        }
        int x = lcs(text1, text2, i+1, j, dp);
        int y = lcs(text1, text2, i, j+1, dp);

        return dp[i][j] = max(x, y);
    }

    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.length();
        int n = text2.length();
        //dp[i][j] represents the lcs from (i, j) to (m-1, n-1)
        vector<vector<int>> dp(m, vector<int>(n, -1));

        return lcs(text1, text2, 0, 0, dp);
    }
};

//Solution 2 : Bottom-Up

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size();
        int n = text2.size();

        //t[i][j] represents lcs upto text1[i-1] and text2[j-1]
        vector<vector<int>> t(m+1, vector<int>(n+1, -1));

        for(int i = 0; i<=m; i++){
            t[i][0] = 0;
        }
        for(int i = 0; i<=n; i++){
            t[0][i] = 0;
        }

        for(int i = 1; i<=m; i++){
            for(int j = 1; j<=n; j++){
                if(text1[i-1] == text2[j-1]){
                    t[i][j] = t[i-1][j-1] + 1;
                }else{
                    t[i][j] = max(t[i-1][j], t[i][j-1]);
                }
            }
        }
        return t[m][n];
    }
};
