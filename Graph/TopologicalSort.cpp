//DFS

class Solution {
  public:
    void dfs(int u, unordered_map<int, vector<int>>& adj, vector<bool>& visited, stack<int>& st){
        visited[u] = true;
        
        for(int& v : adj[u]){
            if(!visited[v]){
                dfs(v, adj, visited, st);
            }
        }
        
        st.push(u);
    }
  
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        // code here
        unordered_map<int, vector<int>> adj;
        
        for(vector<int>& edge : edges){
            int u = edge[0];
            int v = edge[1];
            
            adj[u].push_back(v);
        }
        
        vector<bool> visited(V, false);
        stack<int> st;
        
        for(int i = 0; i<V; i++){
            if(!visited[i]){
                dfs(i, adj, visited, st);
            }
        }
        
        vector<int> result;
        while(!st.empty()){
            result.push_back(st.top());
            st.pop();
        }
        return result;
    }
};

//Kahn's Algorithm (Topological Sort using BFS)

class Solution {
  public:
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        // code here
        unordered_map<int, vector<int>> adj;
        vector<int> indegree(V, 0);
        
        for(vector<int>& edge : edges){
            int u = edge[0];
            int v = edge[1];
            
            adj[u].push_back(v);
            indegree[v]++;
        }
        
        vector<bool> visited(V, false);
        queue<int> que;
        
        for(int i =0; i<V; i++){
            if(indegree[i] == 0){
                visited[i] = true;
                que.push(i);
            }
        }
        
        vector<int> result;
        
        while(!que.empty()){
            int u = que.front();
            result.push_back(u);
            que.pop();
            
            for(int& v : adj[u]){
                if(!visited[v]){
                    indegree[v]--;
                    
                    if(indegree[v] == 0){
                        que.push(v);
                    }
                }
            }
        }
        return result;
        
    }
};