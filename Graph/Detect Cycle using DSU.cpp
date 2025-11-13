class Solution {
  public:
    int find(int i, vector<int>& parent){
        if(parent[i] == i) return i;
        
        return parent[i] = find(parent[i], parent);
    }
  
    void Union(int x, int y, vector<int>& parent, vector<int>& rank){
        int parent_x = find(x, parent);
        int parent_y = find(y, parent);
        
        if(parent_x == parent_y) return;
        
        if(rank[parent_x] > rank[parent_y]){
            parent[parent_y] = parent_x;
        }else if(rank[parent_y] > rank[parent_x]){
            parent[parent_x] = parent_y;
        }else{
            parent[parent_x] = parent_y;
            rank[parent_y]++;
        }
    }
  
    // Function to detect cycle using DSU in an undirected graph.
    int detectCycle(int V, vector<int> adj[]) {
        vector<int> parent(V);
        vector<int> rank(V);
        
        for(int i = 0; i<V; i++){
            parent[i] = i;
            rank[i] = 0;
        }
        
        for(int u = 0; u<V; u++){
            for(int& v : adj[u]){
                if(u < v){
                    int parent_u = find(u, parent);
                    int parent_v = find(v, parent);
                    
                    if(parent_u == parent_v) return true;
                    Union(u, v, parent, rank);
                }
            }
        }
        return false;
    }
};