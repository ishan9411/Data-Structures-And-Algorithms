//Position this line where user code will be pasted.
class Solution {
  public:
    void dfs(int u, vector<bool>& visited, vector<vector<int>> &adj, stack<int>& st){
        visited[u] = true;
        
        for(int v : adj[u]){
            if(!visited[v]){
                dfs(v, visited, adj, st);
            }
        }
        
        st.push(u);
    }
    
    void reversedDfs(int u, vector<bool>& visited, unordered_map<int, vector<int>>& reversedAdj){
        visited[u] = true;
        
        for(int v : reversedAdj[u]){
            if(!visited[v]){
                reversedDfs(v, visited, reversedAdj);
            }
        }
    }
  
    int kosaraju(vector<vector<int>> &adj) {
        
        int n = adj.size();
        
        stack<int> st;
        
        vector<bool> visited(n, false);
        
        for(int i = 0; i<n; i++){
            if(!visited[i]){
                dfs(i, visited, adj, st);
            }
        }
        
        unordered_map<int, vector<int>> reversedAdj;
        
        for(int u = 0; u<n; u++){
            for(int v : adj[u]){
                reversedAdj[v].push_back(u);
            }
        }
        
        visited = vector<bool>(n, false);
        int scc = 0;
        
        while(!st.empty()){
            int node = st.top();
            st.pop();
            
            if(!visited[node]){
                reversedDfs(node, visited, reversedAdj);
                scc++;
            }
        }
        
        return scc;
    }
};