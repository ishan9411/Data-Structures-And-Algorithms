class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();

        int i = 0;
        int j = 0;
        int k = 0;
        while(i < n){
            while(j < n && nums[j] == nums[i]){
                j++;
            }
            nums[k++] = nums[i];
            i = j;
        }
        return k;
    }
};