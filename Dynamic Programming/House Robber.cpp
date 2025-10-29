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

//Solution 2 : Bottom-Up

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        int t[101];

        //t[i] = max stolen money till i house

        //no house
        t[0] = 0;

        //1 house
        t[1] = nums[0];

        for(int i = 2; i<=n; i++){
            int steal = nums[i-1] + t[i-2];  //ye le lo or i-2 tk ka profit lelo
            int skip  = t[i-1];              //i-1 tk ka profit lelo

            t[i] = max(steal, skip);
        }
        return t[n];
    }
};
