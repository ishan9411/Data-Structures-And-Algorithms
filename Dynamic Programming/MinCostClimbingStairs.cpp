//Leetcode : 746. Min Cost Climbing Stairs
//Solution 1 : Top-Down Approach

class Solution {
public:
    vector<int> dp;

    int climbStairs(int i, vector<int>& cost){
        if(i >= cost.size()){
            return 0;
        }
        if(dp[i] != -1) return dp[i];

        int one = cost[i] + climbStairs(i+1, cost);  //add the current cost and move 1 step
        int two = cost[i] + climbStairs(i+2, cost);  //add the current cost and move 2 step

        return dp[i] = min(one, two); //return the min cost by one and two steps
    }

    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        dp.assign(n+1, -1);
        
        return min(climbStairs(0, cost), climbStairs(1, cost));
    }
};

//Solution 2 : Bottom-Up Approach

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n+1, -1);

        dp[n] = 0;  //min cost at n position will be 0.

        for(int i = n-1; i>=0; i--){
            dp[i] = cost[i] + min(dp[i+1], i+2 < n+1 ? dp[i+2] : 0);
        }
        return min(dp[0], dp[1]);  //return the min cost at either starting from 0 or 1
    }
};