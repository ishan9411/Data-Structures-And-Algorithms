//Geeks for geeks : https://www.geeksforgeeks.org/problems/nth-fibonacci-number1335/1?page=1&category=Fibonacci&sortBy=submissions
//Solution 1 : Top-Down Approach (Recursion with Memoization)

class Solution {
  public:
    int fib(int n, vector<int>& dp){
        if(n <= 1) return n;
        if(dp[n] != -1) return dp[n];
        
        return dp[n] = fib(n-1, dp) + fib(n-2, dp);
    }
  
    int nthFibonacci(int n) {
        vector<int> dp(n+1, -1);
        return fib(n, dp);
        
    }
};

//Solution 2 : Bottom-Up Approach (Tabulation Method)

class Solution {
  public:
    int fib(int n, vector<int>& dp){
        dp[0] = 0;
        dp[1] = 1;
        
        for(int i = 2; i<=n; i++){
            dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[n];
    }
  
    int nthFibonacci(int n) {
        vector<int> dp(n+1, -1);
        return fib(n, dp);
        
    }
};

//Bottom-Up using O(1) Space

class Solution {
  public:
    int fib(int n, vector<int>& dp){
        dp[0] = 0;
        dp[1] = 1;
        
        for(int i = 2; i<=n; i++){
            dp[i % 3] = dp[(i-1) % 3] + dp[(i-2) % 3];
        }
        return dp[n % 3];
    }
  
    int nthFibonacci(int n) {
        vector<int> dp(3, -1);
        return fib(n, dp);
        
    }
};