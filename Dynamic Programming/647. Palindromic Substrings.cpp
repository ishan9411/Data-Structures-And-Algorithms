//Solution 1 : Recursion + Memoization

class Solution {
public:
    int t[1001][1001]; //t[i][j] = true means substring [i, j] is a valid palindrome

    bool check(int i, int j, string s){
        if(i > j){
            return true;
        }
        if(t[i][j] != -1){
            return t[i][j];
        }
        if(s[i] == s[j]){
            return t[i][j] = check(i+1, j-1, s);
        }
        return t[i][j] = false;
    }

    int countSubstrings(string s) {
        int n = s.length();
        memset(t, -1, sizeof(t));

        int count = 0;

        for(int i = 0; i<n; i++){
            for(int j = i; j<n; j++){
                if(check(i, j, s)){  //check every i to j is a palindrome or not
                    count++;
                }
            }
        }
        return count;
    }
};

//Solution 2 : Bottom-Up

class Solution {
public:
    int countSubstrings(string s) {
        int n = s.length();
        vector<vector<bool>> t(n+1, vector<bool>(n+1, false));
        int count = 0;

        for(int L = 1; L<=n; L++){
            for(int i = 0; i+L-1 < n;i++){
                int j = i+L-1;

                if(i == j){  //1 Length
                    t[i][i] = true;
                }
                else if(i+1 == j){  //2 Length
                    t[i][j] = (s[i] == s[j]);
                }
                else{   // > 2 Length
                    t[i][j] = (s[i] == s[j] && t[i+1][j-1]);
                }
                if(t[i][j]){
                    count++;
                }
            }
        }
        return count;
    }
};