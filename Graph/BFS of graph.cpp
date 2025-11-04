//GFG

class Solution {
  public:
    vector<int> bfs(vector<vector<int>> &adj) {
        // code here
        queue<int> que;
        vector<bool> visited(adj.size(), false);
        vector<int> ans;
        
        que.push(0);
        visited[0] = true;
        
        while(!que.empty()){
            int v = que.front();
            que.pop();
            ans.push_back(v);
            
            for(int ngbr : adj[v]){
                if(!visited[ngbr]){
                    que.push(ngbr);
                    visited[ngbr] = true;
                }
            }
        }
        return ans;
    }
};