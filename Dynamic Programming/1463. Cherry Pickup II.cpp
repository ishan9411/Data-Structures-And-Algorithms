//Solution 1 : Top-Down Approach

class Solution {
public:
    int maxCherry(int row, int c1, int c2, vector<vector<int>>& grid, int m, int n, vector<vector<vector<int>>>& dp){
        if(row == m-1){
            if(c1 != c2){
                return grid[row][c1] + grid[row][c2];
            }
            return grid[row][c1];
        }

        if(dp[row][c1][c2] != -1) return dp[row][c1][c2];

        int ll = INT_MIN;
        if(c1-1 >= 0 && c2-1 >=0){
            ll = maxCherry(row+1, c1-1, c2-1, grid, m, n, dp);
        }

        int ld = INT_MIN;
        if(c1-1 >= 0){
            ld = maxCherry(row+1, c1-1, c2, grid, m, n, dp);
        }

        int lr = INT_MIN;
        if(c1-1 >= 0 && c2+1 < n){
            lr = maxCherry(row+1, c1-1, c2+1, grid, m, n, dp);
        }

        int dl = INT_MIN;
        if(c2-1 >= 0){
            dl = maxCherry(row+1, c1, c2-1, grid, m, n, dp);
        }

        int dd = maxCherry(row+1, c1, c2, grid, m, n, dp);

        int dr = INT_MIN;
        if(c2+1 < n){
            dr = maxCherry(row+1, c1, c2+1, grid, m, n, dp);
        }

        int rl = INT_MIN;
        if(c2-1 >= 0 && c1+1 < n){
            rl = maxCherry(row+1, c1+1, c2-1, grid, m, n, dp);
        }

        int rd = INT_MIN;
        if(c1+1 < n){
            rd = maxCherry(row+1, c1+1, c2, grid, m, n, dp);
        }

        int rr = INT_MIN;
        if(c1+1 < n && c2+1 < n){
            rr = maxCherry(row+1, c1+1, c2+1, grid, m, n, dp);
        }

        int maxi = max({ll, ld, lr, dl, dd, dr, rl, rd, rr});

        if(c1 != c2){
            return dp[row][c1][c2] = maxi + grid[row][c1] + grid[row][c2];
        }
        return dp[row][c1][c2] = maxi + grid[row][c1];
    }

    int cherryPickup(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(n, -1)));

        return maxCherry(0, 0, n-1, grid, m, n, dp);
    }
};