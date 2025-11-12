//Solution 1 : DFS

class Solution {
public:
    bool dfs(int source, int destination, unordered_map<int, vector<int>>& adj, vector<bool>& visited){
        visited[source] = true;

        for(int& v : adj[source]){
            if(v == destination) return true;
            if(!visited[v] && dfs(v, destination, adj, visited)){
                return true;
            }
        }
        return false;
    }

    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        if(n == 1) return true;
        unordered_map<int, vector<int>> adj;

        for(vector<int>& edge : edges){
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<bool> visited(n, false);

        if(dfs(source, destination, adj, visited)){
            return true;
        }
        return false;
    }
};