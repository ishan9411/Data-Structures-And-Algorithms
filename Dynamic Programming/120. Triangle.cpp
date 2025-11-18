//Solution 1 : Top-Down Approach

class Solution {
public:
    int minSum(int i, int j, vector<vector<int>>& triangle, vector<vector<int>>& dp){
        if(i == triangle.size()-1) return triangle[i][j];

        if(dp[i][j] != -1) return dp[i][j];

        return triangle[i][j] + min(minSum(i+1, j, triangle, dp), minSum(i+1, j+1, triangle, dp));
    }

    int minimumTotal(vector<vector<int>>& triangle) {
        int m = triangle.size();
    
        vector<vector<int>> dp(m, vector<int>(m, -1));
        return minSum(0, 0, triangle, dp);
    }
};

//Solution 2 : Bottom-Up Approach

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> t = triangle; //same size dp (O(n^2))
        //t[i][j] represents minPathSum required from [i][j] to reach last row

        for(int row = n-2; row >= 0; row--){
            for(int col = 0; col<=row; col++){
                t[row][col] = triangle[row][col] + min(t[row+1][col], t[row+1][col+1]);
            }
        }
        return t[0][0];
    }
};

//Solution 3 : Space Optimized Bottom-Up 

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<int> t = triangle[n-1];  //we only need the (row+1) row, so we only save that

        for(int row = n-2; row >= 0; row--){
            for(int col = 0; col<=row; col++){
                t[col] = triangle[row][col] + min(t[col], t[col+1]);
            }
        }
        return t[0];
    }
};

//Solution 4 : Bottom-Up another method  (manipulating the input)->asks interviewer that can we do it?

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        
        //t[i]][j] represents minPathSum to reach [i][j] from [0][0]

        for(int row = 1; row < n; row++){
            for(int col = 0; col<=row; col++){
                triangle[row][col] = triangle[row][col] + 
                                    min(triangle[row-1][max(col-1, 0)], triangle[row-1][min(col, (int)triangle[row-1].size()-1)]);
            }
        }
        return *min_element(begin(triangle[n-1]), end(triangle[n-1]));
    }
};