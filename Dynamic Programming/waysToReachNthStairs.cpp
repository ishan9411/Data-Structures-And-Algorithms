//geeks for geeks : https://www.geeksforgeeks.org/problems/count-ways-to-reach-the-nth-stair-1587115620/1
//Solution 1 : Top-Down Approach

class Solution {
  public:
    int climbStairsWays(int n, vector<int>& dp){
        if(n < 0) return 0;
        if(n == 0) return 1;
        
        if(dp[n] != -1) return dp[n];
        
        int one = climbStairsWays(n-1, dp);
        int two = climbStairsWays(n-2, dp);
        
        return dp[n] = one + two;
    }
  
    int countWays(int n) {
        vector<int> dp(n+1, -1);
        return climbStairsWays(n, dp);
        
    }
};


//Solution 2 : Bottom-Up Approach

class Solution {
  public:
    int climbStairsWays(int n, vector<int>& dp){
        dp[0] = 1;
        dp[1] = 1;
        
        for(int i = 2; i<=n; i++){
            dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[n];
    }
  
    int countWays(int n) {
        vector<int> dp(n+1, -1);
        return climbStairsWays(n, dp);
        
    }
};
