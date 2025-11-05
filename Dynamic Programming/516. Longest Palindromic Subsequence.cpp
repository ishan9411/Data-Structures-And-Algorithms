//Solution 1 : Recursion + Memoization

class Solution {
public:
    int n;
    vector<vector<int>> t;

    int LPS(int i, int j, string s){
        if(i > j){
            return 0;
        }
        if(i == j){
            return 1;
        }
        if(t[i][j] != -1){
            return t[i][j];
        }

        if(s[i] == s[j]){
            return t[i][j] = 2 + LPS(i+1, j-1, s);
        }else{
            return t[i][j] = max(LPS(i+1, j, s), LPS(i, j-1, s));
        }
    }

    int longestPalindromeSubseq(string s) {
        n = s.length();
        t.resize(n+1, vector<int>(n+1, -1));

        return LPS(0, n-1, s);
    }
};

//Solution 2 : Bottom-Up

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();

        //t[i][j] represent [i,j]->LPS
        vector<vector<int>> t(n, vector<int>(n, 0));

        for(int i = 0; i<n; i++){
            t[i][i] = 1;
        }

        for(int L = 2; L<=n; L++){
            for(int i = 0; i+L-1<n; i++){
                int j = i + L - 1;

                if(s[i] == s[j]){
                    t[i][j] = 2 + t[i+1][j-1];
                }else{
                    t[i][j] = max(t[i+1][j], t[i][j-1]);
                }
            }
        }

        return t[0][n-1];
    }
};