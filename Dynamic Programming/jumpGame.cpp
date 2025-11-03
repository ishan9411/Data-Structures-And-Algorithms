//Leetcode : 55. Jump Game
//Solution 1 : Recurision + Memoization  T.C. = O(n^2)

class Solution {
public:
    vector<int> t;

    bool jump(vector<int>& nums, int i){
        if(i == nums.size()-1){
            return true;
        }
        if(t[i] != -1) return t[i];

        for(int j = 1; j<=nums[i]; j++){  //checking all the options
            if(jump(nums, i+j)){
                return true;        //will keep returning true if i finds any way to reach last
            }
        }
        return t[i] = false;
    }

    bool canJump(vector<int>& nums) {
        int n = nums.size();
        t.assign(n+1, -1);

        return jump(nums, 0);
    }
};

//Solution 2 : Bottom-Up

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        vector<int> t(n, 0);  //t[i] = true means i can reach i, false means i cannot reach this i

        t[0] = 1; //can always reach the first index

        for(int i = 1; i<=n-1; i++){
            for(int j = i-1; j>=0; j--){ //go back and look if any way is possible
                if(j+nums[j] >= i && t[j]){  //t[j] should be reachable & from t[j] we can reach i
                    t[i] = 1;
                    break;
                }
            }
        }
        return t[n-1];
    }
};

//Solution 3 : Smart Solution => O(n)

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();

        int maxReachable = 0;

        for(int i = 0; i<n; i++){
            if(i > maxReachable){ //if i cannot reach the i, I can't go further
                return false;
            }
            maxReachable = max(maxReachable, i + nums[i]); //calculating maxReachable every time
        }
        return true;
    }
};