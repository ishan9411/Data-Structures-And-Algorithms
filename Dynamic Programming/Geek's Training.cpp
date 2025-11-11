//GFG
//Solution 1 : Recursion + Memoization

class Solution {
  public:
    int maxMerits(int i, int j, vector<vector<int>>& arr, vector<vector<int>>& dp){
        if(i >= arr.size()){
            return 0;
        }
        
        if(dp[i][j] != -1) return dp[i][j];
        
        int m = 0;
        for(int k = 0; k<3; k++){
            if(k == j) continue;
            m = max(m, arr[i][k] + maxMerits(i+1, k, arr, dp));
        }
        return dp[i][j] = m;
    }
  
    int maximumPoints(vector<vector<int>>& arr) {
        int n = arr.size();
        vector<vector<int>> dp(n+1, vector<int>(4, -1));
        return maxMerits(0, 3, arr, dp);
        
    }
};