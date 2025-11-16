// Using Priority Queue

class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        // Code here
        unordered_map<int, vector<pair<int, int>>> adj;
        
        for(vector<int>& edge : edges){
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];
            
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        
        vector<int> result(V, INT_MAX);
        result[src] = 0;
        pq.push({0,src});
        
        while(!pq.empty()){
            int dist = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            
            
            for(pair<int, int>& ngbr : adj[node]){
                int v = ngbr.first;
                int w = ngbr.second;
                
                if(dist + w < result[v]){
                    result[v] = dist + w;
                    pq.push({dist+w, v});
                }
            }
        }
        return result;
    }
};