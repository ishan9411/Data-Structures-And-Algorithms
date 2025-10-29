//Leetcode : 198. House Robber
//Solution 1 : Recursion + Memoization

class Solution {
public:
    int solve(int i, vector<int>& nums, vector<int>& dp){
        if(i >= nums.size()){
            return 0;
        }

        if(dp[i] != -1) return dp[i];

        int rob = nums[i] + solve(i+2, nums, dp); //if robbed dont rob just next house, starting to rob from i+2

        int skip = solve(i+1, nums, dp); //if not robbed, move to next house(i+1)

        return dp[i] = max(rob, skip); //return the max value from both step
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n+1, -1);
        return solve(0, nums, dp);
    }
};

