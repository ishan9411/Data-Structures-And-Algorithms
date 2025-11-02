//Leetcode : 72. Edit Distance
//Solution 1 : Recursion + Memoization

class Solution {
public:
    vector<vector<int>> t;  //t[i][j] represents med from i to m & j to n

    int med(string word1, string word2, int i, int j){
        if(i >= word1.length()){
            return word2.length() - j;          //rest will have to be deleted
        }
        if(j >= word2.length()){
            return word1.length() - i;
        }
        if(t[i][j] != -1) return t[i][j];

        if(word1[i] == word2[j]){
            return t[i][j] = med(word1, word2, i+1, j+1);   //both equal move ahead
        }

        int del = med(word1, word2, i+1, j) + 1;   
        int ins = med(word1, word2, i, j+1) + 1; 
        int rep = med(word1, word2, i+1, j+1) + 1;

        return t[i][j] = min(del, min(ins, rep));
    }

    int minDistance(string word1, string word2) {
        t.assign(word1.length(), vector<int>(word2.length(), -1));
        return med(word1, word2, 0, 0);
    }
};

//Solution 2 : Bottom-Up

class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.length();
        int n = word2.length();
        vector<vector<int>> t(m+1, vector<int>(n+1, 0));

        for(int i = 0; i<=m; i++){
            t[i][0] = i;
        }
        for(int i = 0; i<=n; i++){
            t[0][i] = i;
        }
        for(int i = 1; i<=m; i++){
            for(int j = 1; j<=n; j++){
                if(word1[i-1] == word2[j-1]){
                    t[i][j] = t[i-1][j-1];
                }else{
                    t[i][j] = min(t[i][j-1], min(t[i-1][j], t[i-1][j-1])) + 1;
                }
            }
        }
        return t[m][n];
    }
};