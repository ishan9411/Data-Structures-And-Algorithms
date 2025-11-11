class Solution {
  public:
    bool isCycleDFS(unordered_map<int, vector<int>>& adj, int u, vector<bool>& visited, vector<bool>& inRecursion){
        visited[u] = true;
        inRecursion[u] = true;   //i visited this node in this recursion also
        
        for(int& v : adj[u]){
            if(!visited[v] && isCycleDFS(adj, v, visited, inRecursion)){
                return true;
            }else if(inRecursion[v]){  //i got a visited node in this recursion
                return true;
            }
        }
        
        inRecursion[u] = false;  //change to false when coming back from recursion
        return false;
    }
  
    bool isCyclic(int V, vector<vector<int>> &edges) {
        // code here
        unordered_map<int, vector<int>> adj;
        
        for(vector<int>& edge : edges){
            int u = edge[0];
            int v = edge[1];
            
            adj[u].push_back(v);
        }
        
        vector<bool> visited(V, false);
        vector<bool> inRecursion(V, false);
        
        for(int i = 0; i<V; i++){
            if(!visited[i] && isCycleDFS(adj, i, visited, inRecursion))
                return true;
        }
        return false;
    }
};