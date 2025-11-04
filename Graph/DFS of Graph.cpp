//GFG

class Solution {
  public:
    void dfs(int node, vector<vector<int>>& adj, vector<bool>& visited, vector<int>& ans){
        visited[node] = true;
        ans.push_back(node);
        
        for(int ngbr : adj[node]){
            if(!visited[ngbr]){
                dfs(ngbr, adj, visited, ans);
            }
        }
    }
    
    vector<int> dfs(vector<vector<int>>& adj) {
        // Code here
        vector<int> ans;
        vector<bool> visited(adj.size(), false);
        
        dfs(0, adj, visited, ans);
        
        return ans;
    }
};