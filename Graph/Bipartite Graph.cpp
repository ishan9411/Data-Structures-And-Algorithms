//DFS

class Solution {
  public:
    bool checkBipartiteDFS(unordered_map<int, vector<int>>& adj, int u, vector<int>& color, int currColor){
        color[u] = currColor;
        
        for(int& v : adj[u]){
            if(color[v] == color[u]) return false;
            if(color[v] == -1){
                int colorV = 1 - currColor;
                if(checkBipartiteDFS(adj, v, color, colorV) == false){
                    return false;
                }
            }
        }
        return true;
    }
  
    bool isBipartite(int V, vector<vector<int>> &edges) {
        // Code here
        unordered_map<int, vector<int>> adj;
        
        for(vector<int>& edge : edges){
            int u = edge[0];
            int v = edge[1];
            
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        vector<int> color(V, -1);
        
        for(int i = 0; i<V; i++){
            if(color[i] == -1){
                if(checkBipartiteDFS(adj, i, color, 1) == false){
                    return false;
                }
            }
        }
        return true;
    }
};

//BFS

class Solution {
  public:
    bool checkBipartiteBFS(unordered_map<int, vector<int>>& adj, int node, vector<int>& color, int currColor){
        queue<int> que;
        que.push(node);
        color[node] = currColor;
        
        while(!que.empty()){
            int u = que.front();
            que.pop();
            
            for(int& v : adj[u]){
                if(color[v] == color[u]){
                    return false;
                }
                else if(color[v] == -1){
                    que.push(v);
                    color[v] = 1 - color[u];
                }
            }
        }
        return true;
    }
  
    bool isBipartite(int V, vector<vector<int>> &edges) {
        // Code here
        unordered_map<int, vector<int>> adj;
        
        for(vector<int>& edge : edges){
            int u = edge[0];
            int v = edge[1];
            
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        vector<int> color(V, -1);
        
        for(int i = 0; i<V; i++){
            if(color[i] == -1){
                if(checkBipartiteBFS(adj, i, color, 1) == false){
                    return false;
                }
            }
        }
        return true;
    }
};