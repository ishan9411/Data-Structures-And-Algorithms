#include<bits/stdc++.h>
using namespace std;

void dfs(int u, int parent, unordered_map<int, vector<int>>& adj, vector<bool>& visited, vector<int>& tin, vector<int>& low, int timer){
    visited[u] = true;

    tin[u] = low[u] = timer++;

    for(int v : adj[u]){
        if(v == parent){
            continue;
        }

        if(visited[v]){   //back edge 
            low[u] = min(low[u], tin[v]);
        }else{
            dfs(v, u, adj, visited, tin, low, timer);
            low[u] = min(low[u], low[v]);
            if(low[v] > tin[u]){
                cout << "bridge: " << u << " " << v << endl;
            }
        }
    }
}

int main(){
    vector<vector<int>> edges = {{0, 1}, {1, 2}, {2, 0}, {2, 3}, {3, 4}};
    int n = 5;

    unordered_map<int, vector<int>> adj;

    for(vector<int>& edge : edges){
        int u = edge[0];
        int v = edge[1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<bool> visited(n, false);
    vector<int> tin(n, -1);
    vector<int> low(n, -1);

    for(int i = 0; i<n; i++){
        if(!visited[i]){
            dfs(i, -1, adj, visited, tin, low, 0);
        }
    }
}