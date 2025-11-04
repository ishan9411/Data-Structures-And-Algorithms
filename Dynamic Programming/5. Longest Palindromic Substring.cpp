//Solution 1 : Recursion + Memoization

class Solution {
public:
    int t[1001][1001];

    bool solve(int i, int j, string s){
        if(i > j){
            return true;
        }
        if(t[i][j] != -1){
            return t[i][j];
        }
        if(s[i] == s[j]){
            return t[i][j] = solve(i+1, j-1, s);
        }
        return t[i][j] = false;
    }

    string longestPalindrome(string s) {
        int n = s.length();
        memset(t, -1, sizeof(t));

        int maxLen = 0;
        int sp = 0;

        for(int i = 0; i<n; i++){
            for(int j = i; j<n; j++){
                if(solve(i, j, s)){
                    if(j-i+1 > maxLen){
                        maxLen = j-i+1;
                        sp = i;
                    }
                }
            }
        }
        return s.substr(sp, maxLen);
    }
};

//Soution 2 : Bottom-Up

class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();

        vector<vector<bool>> t(n, vector<bool>(n, false));
        int start = 0;
        int maxLen = 0;

        for(int L = 1; L<=n; L++){
            for(int i = 0; i+L-1<n; i++){
                int j = i+L-1;

                if(i == j){
                    t[i][i] = true;
                    start = i;
                    maxLen = 1;
                }else if(i+1 == j){
                    if(s[i] == s[j]){
                        t[i][j] = true;
                        start = i;
                        maxLen = 2;
                    }
                }else if(s[i] == s[j] && t[i+1][j-1]){
                    t[i][j] = true;
                    start = i;
                    maxLen = L;
                }
            }
        }
        return s.substr(start, maxLen);
    }
};