//NeetCode

//Solution 1 : DFS

class Solution {
public:
    void dfs(int node, vector<vector<int>>& adj, vector<bool>& visited, vector<int>& component){
        visited[node] = true;
        component.push_back(node);

        for(int ngbr : adj[node]){
            if(!visited[ngbr]){
                dfs(ngbr, adj, visited, component);
            }
        }
    }

    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);

        for(vector<int>& e : edges){
            int u = e[0];
            int v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<bool> visited(n, false);
        
        vector<vector<int>> components;

        for(int i  = 0; i<n; i++){
            if(!visited[i]){
                vector<int> component;
                dfs(i, adj, visited, component);
                components.push_back(component);
            }
        }
        return components.size();
    }
};


//Solution 2 : BFS

class Solution {
public:

    void bfs(int node, vector<vector<int>>& adj, vector<bool>& visited, vector<int>& component){
        queue<int> que;
        que.push(node);
        visited[node] = true;

        while(!que.empty()){
            int curr = que.front();
            que.pop();
            component.push_back(curr);

            for(int ngbr : adj[curr]){
                if(!visited[ngbr]){
                    que.push(ngbr);
                    visited[ngbr] = true;
                }
            }
        }
        
    }

    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);

        for(vector<int>& e : edges){
            int u = e[0];
            int v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<bool> visited(n, false);
        
        vector<vector<int>> components;

        for(int i = 0; i<n; i++){
            if(!visited[i]){
                vector<int> component;
                bfs(i, adj, visited, component);
                components.push_back(component);
            }
        }
        
        return components.size();
    }
};
