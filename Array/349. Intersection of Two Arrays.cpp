class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        sort(begin(nums1), end(nums1));
        sort(begin(nums2), end(nums2));

        vector<int> result;

        int i = 0;
        int j = 0;

        while(i<nums1.size() && j<nums2.size()){
            if(nums1[i] == nums2[j]){
                if(!result.empty() && result.back() != nums1[i]){
                    result.push_back(nums1[i]);
                }else if(result.empty()){
                    result.push_back(nums1[i]);
                }
                i++;
                j++;
            }
            else if(nums1[i] < nums2[j]){
                i++;
            }
            else{
                j++;
            }
        }
        return result;
    }
};