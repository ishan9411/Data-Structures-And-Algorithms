//GFG : Rod Cutting
//Solution 1 : Recursion + Memoization

class Solution {
  public:
  
    vector<int> dp;
  
    int maxVal(vector<int>& price, int n){
        if(dp[n] != -1) return dp[n];
        if(n <= 0) return 0;
        
        int mv = price[n-1];  //ayse hi bech dia
        
        for(int k = 1; k<n; k++){  //cut lgakr bechre h ab
            int v = price[k-1] + maxVal(price, n-k);
            if(v > mv){
                mv = v;
            }
        }
        return dp[n] = mv;
    }
  
    int cutRod(vector<int> &price) {
        // code here
        dp.assign(price.size()+1, -1);
        return maxVal(price, price.size());
    }
};