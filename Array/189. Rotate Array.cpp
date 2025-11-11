class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k%n;           //round the value to less than size of array

        reverse(begin(nums), begin(nums)+(n-k));  //rotate array from start to n-k-1
        reverse(begin(nums)+(n-k), end(nums));    //rotate array from n-k idx to last
        reverse(begin(nums), end(nums));          //rotate the complete array
    }
};