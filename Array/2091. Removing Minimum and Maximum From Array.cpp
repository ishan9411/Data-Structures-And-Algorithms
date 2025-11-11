class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        int result = INT_MAX;
        int minIdx = 0;
        int maxIdx = 0;

        for(int i = 0; i<n; i++){
            if(nums[i] < nums[minIdx]){
                minIdx = i;
            }
            if(nums[i] > nums[maxIdx]){
                maxIdx = i;
            }
        }

        //Scenerio 1 : both elements deleted from front
        if(minIdx > maxIdx){
            result = min(result, minIdx+1);
        }else{
            result = min(result, maxIdx+1);
        }

        //Scenerio  2 : both elements deleted from back
        if(maxIdx < minIdx){
            result = min(result, n-maxIdx);
        }else{
            result = min(result, n-minIdx);
        }

        //Scenerio 3 : 1 deleted from front and 1 from back
        if(maxIdx < minIdx){
            result = min(result, (maxIdx+1) + (n-minIdx));
        }else{
            result = min(result, (minIdx+1) + (n-maxIdx));
        }

        return result;
    }
};