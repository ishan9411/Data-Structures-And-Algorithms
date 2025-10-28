//Leetcode : 279. Perfect Squares
//Solution 1 : Recursion + Memoization

class Solution {
public:
    int dp[10001];

    int helper(int n){
        if(n == 0){
            return 0;
        }
        if(dp[n] != -1) return dp[n];

        int minCount = INT_MAX;

        for(int i = 1; i*i<=n; i++){
            int result = 1 + helper(n-i*i);
            minCount = min(minCount, result);
        }
        return dp[n] = minCount;
    }

    int numSquares(int n) {
        memset(dp, -1, sizeof(dp));
        return helper(n);
    }
};

//Solution 2 : Bottom-Up

class Solution {
public:
    int numSquares(int n) {
        vector<int> t(n+1, 100000);

        t[0] = 0;

        for(int i = 1; i<=n; i++){
            for(int j = 1; j*j<=i; j++){
                t[i] = min(t[i], 1 + t[i-j*j]);
            }
        }
        return t[n];
    }
};