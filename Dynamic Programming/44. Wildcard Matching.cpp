//Solution 1 : Recursion + Memoization

class Solution {
public:
    bool match(int i, int j, string& s, string& p, vector<vector<int>>& dp){
        if(i < 0 && j < 0){  //Both matches
            return true;
        }
        if(i >= 0 && j < 0){ //still some string left to match
            return false;
        }
        if(i < 0 && j >= 0){  //pattern is only left, check if pattern has all stars
            for(int k = j; k>=0; k--){
                if(p[k] != '*') return false;
            }
            return true;
        }

        if(dp[i][j] != -1) return dp[i][j];

        if(s[i] == p[j] || p[j] == '?'){
            return dp[i][j] = match(i-1, j-1, s, p, dp); //matches
        }
        if(p[j] == '*'){
                              //'*' means nothing       //'*' matches 1, can match more
            return dp[i][j] = match(i, j-1, s, p, dp) | match(i-1, j, s, p, dp);
        }
        return dp[i][j] = false; //not matches
    }

    bool isMatch(string s, string p) {
        int n = s.length();
        int m = p.length();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return match(n-1, m-1, s, p, dp);
    }
};

//Solution 2 : Bottom-Up (Convert recursion to 1-based indexing, then to bottom up)

class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.length();
        int m = p.length();
        vector<vector<int>> dp(n+1, vector<int>(m+1, -1));

        dp[0][0] = true;

        for(int i = 1; i<=n; i++){
            dp[i][0] = false;
        }

        for(int j = 1; j<=m; j++){
            bool flag = true;
            for(int k = 1; k<=j; k++){
                if(p[k-1] != '*'){
                    flag = false;
                    break;
                }
            }
            dp[0][j] = flag;
        }

        for(int i = 1; i<=n; i++){
            for(int j = 1; j<=m; j++){

                if(s[i-1] == p[j-1] || p[j-1] == '?'){
                    dp[i][j] = dp[i-1][j-1];
                }
                else if(p[j-1] == '*'){
                    dp[i][j] = dp[i][j-1] || dp[i-1][j];
                }
                else {
                    dp[i][j] = false;
                }
            }
        }

        return dp[n][m];
    }
};