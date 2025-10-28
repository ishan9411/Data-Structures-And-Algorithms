//Leetcode : 338. Counting Bits
//Solution 1 : O(nlogn)
class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans(n+1, 0);

        for(int i = 0; i<=n; i++){
            int num = i;
            int ones = 0;
            while(num){
                if(num & 1 == 1){
                    ones++;
                }
                num = num >> 1;
            }
            ans[i] = ones;
        }
        return ans;
    }
};

//Solution 2 : Bottom-Up Approach

class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> result(n+1, 0);

        if(n == 0) return result;

        result[0] = 0;

        for(int i = 1; i<=n; i++){
            if(i%2 == 0){
                result[i] = result[i/2];
            }else{
                result[i] = result[i/2] + 1;
            }
        }
        return result;
    }
};

//Solution 3 : Brian Kernighan's Algorithm

class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> result(n+1, 0);

        result[0] = 0;

        for(int i = 1; i<=n; i++){
            result[i] = result[i&(i-1)] + 1; //i&(i-1) removes rightmost set bit from n
        }
        return result;
    }
};
/* 
i & (i - 1): This operation removes the least significant 1 bit from i. It works because when you subtract 1 from a number, all the bits after the rightmost 1 bit (including the rightmost 1 bit) are flipped. So, the i & (i - 1) clears the rightmost 1 bit.

ans[i & (i - 1)] + 1: This updates the count of 1s for i based on the previous count (i & (i - 1) refers to the number with the least significant 1 bit removed).
*/