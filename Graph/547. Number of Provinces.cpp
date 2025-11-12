//Solution 1 : DFS

class Solution {
public:
    void dfs(int u, unordered_map<int, vector<int>>& adj, vector<bool>& visited){
        visited[u] = true;

        for(int& v : adj[u]){
            if(!visited[v]){
                dfs(v, adj, visited);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        unordered_map<int, vector<int>> adj;

        for(int i = 0; i<n; i++){
            for(int j = 0; j<n; j++){
                if(isConnected[i][j] == 1){
                    adj[i+1].push_back(j+1);
                    adj[j+1].push_back(i+1);
                }
            }
        }

        vector<bool> visited(n+1, false);
        int provinces = 0;

        for(int i = 1; i<=n; i++){
            if(!visited[i]){
                provinces++;
                dfs(i, adj, visited);
            }
        }
        return provinces;
    }
};

//Solution 2 : BFS

class Solution {
public:
    void bfs(int u, unordered_map<int, vector<int>>& adj, vector<bool>& visited){
        queue<int> que;
        que.push(u);
        visited[u] = true;

        while(!que.empty()){
            int u = que.front();
            que.pop();

            for(int& v : adj[u]){
                if(!visited[v]){
                    que.push(v);
                    visited[v] = true;
                }
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        unordered_map<int, vector<int>> adj;

        for(int i = 0; i<n; i++){
            for(int j = 0; j<n; j++){
                if(isConnected[i][j] == 1){
                    adj[i+1].push_back(j+1);
                    adj[j+1].push_back(i+1);
                }
            }
        }

        vector<bool> visited(n+1, false);
        int provinces = 0;

        for(int i = 1; i<=n; i++){
            if(!visited[i]){
                provinces++;
                bfs(i, adj, visited);
            }
        }
        return provinces;
    }
};