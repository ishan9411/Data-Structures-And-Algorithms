class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int, int> mp;

        for(int num : nums){  //calculated frequency
            mp[num]++;
        }

        int maxFreq = 0;
        for(auto [element , freq] : mp){
            maxFreq = max(freq, maxFreq);   //calculated maximum freq occuring
        }
        int maxFreqCount = 0;
        for(auto [element, freq] : mp){
            if(freq == maxFreq){
                maxFreqCount += freq;   //calculating the occurence of maximum freq
            }
        }
        return maxFreqCount;
    }
};