//Leetcode : 45. Jump Game II
//Solution 1 : Recursion + Memoization

class Solution {
public:
    vector<int> dp;

    int minJump(vector<int>& nums, int n, int i){
        if(i == n-1) return 0;  //reaching n-1 tp n-1, we need 0 jumps
        if(i > n-1) return INT_MAX;  //not possible to go to n-1

        if(dp[i] != -1) return dp[i];

        int minJ = INT_MAX; //initially, maan kr chlo we cannot reach
        for(int j = 1; j<=nums[i]; j++){
            int jump = minJump(nums, n, i+j);
            if(jump != INT_MAX){  //we can reach now
                minJ = min(minJ, jump + 1);  //we can reach then add this 1 jump and min Jumps from i+j index
            }
        }

        return dp[i] = minJ; //dp[i] stores the min Jumps required to reach n-1
    }

    int jump(vector<int>& nums) {
        int n = nums.size();
        dp.assign(n, -1);

        return minJump(nums, n, 0);
    }
};

//Solution 2 : Botto- Up

class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> t(n, -1); //t[i] represents min jumps from 0 to reach i

        t[0] = 0; //min jumps for reaching 0 from 0

        for(int i = 1; i<=n-1; i++){
            int miniJ = INT_MAX;
            for(int j = i-1; j>=0; j--){
                if(j+nums[j] >= i && t[j] != INT_MAX){ //t[j] is reachable from 0
                    miniJ = min(miniJ, t[j] + 1);
                }
            }
            t[i] = miniJ;  //INT_MAX for any index represents that it is not reachable from any previous index
        }
        return t[n-1];
    }
};

//Soltuion 3 : Greedy Algorithm (Always checking farhtest)

class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();

        int l = 0;
        int r = 0;
        int jumps = 0;

        while(r < n-1){
            int farthest = 0;
            for(int i = l; i<=r; i++){
                farthest = max(i+nums[i], farthest);
            }
            l = r+1;
            r = farthest;
            jumps++;
        }
        return jumps;
    }
};