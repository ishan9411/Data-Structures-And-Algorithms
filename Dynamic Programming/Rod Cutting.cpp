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

//Solution 2 : Bottom-Up

// User function Template for C++

class Solution {
  public:
  
    int cutRod(vector<int> &price) {
        // code here
        int n = price.size();
        vector<int> dp(n+1, -1);
        
        dp[0] = 0;  //for 0 length maxValue will be 0
        dp[1] = price[0]; //for 1 length maxValue will be the 1 length value
        
        for(int i = 2; i<=n; i++){   //dp[i] represents the max Value i can get from a rod of length 'i'
            dp[i] = price[i-1]; //cut nhi kra
            for(int k = 1; k<i; k++){  //cut kra jbtk cut lgg skta thh
                dp[i] = max(dp[i], dp[k] + dp[i-k]);  //dono parts ka max value dp se dekhli
            }
        }
        
        return dp[n];
    }
};