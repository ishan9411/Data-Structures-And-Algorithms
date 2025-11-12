//Solution 1 : Hash Table

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();

        unordered_map<int, int> mp;

        for(int num : nums){
            mp[num]++;
        }
        for(auto [num, count] : mp){
            if(count > n/2) return num;
        }
        return -1;
    }
};

//Solution 2 : Moore's Algo

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 0;
        int candidate = 0;

        for(int num : nums){
            if(count == 0) candidate = num;

            count += num == candidate? 1 : -1;
        }
        return candidate;
    }
};