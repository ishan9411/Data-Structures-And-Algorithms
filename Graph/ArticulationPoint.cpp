#include<bits/stdc++.h>
using namespace std;

void dfs(int u, int parent, unordered_map<int, vector<int>>& adj, vector<bool>& visited, vector<int>& tin, vector<int>& low, int timer, vector<int>& AP){
    visited[u] = true;

    low[u] = tin[u] = timer++;
    int children = 0;

    for(int v : adj[u]){
        if(!visited[v]){
            children++;
            dfs(v, u, adj, visited, tin, low, timer, AP);
            low[u] = min(low[u], low[v]);
            if(parent != -1 && low[v] >= tin[u]){
                AP[u] = 1;
            }
        }
        else if(v != parent){    //back edge
            low[u] = min(low[u], tin[v]);
        }
    }

    if(parent == -1 && children > 1){
        AP[u] = 1;
    }
}

int main(){
    vector<vector<int>> edges = {{0, 1}, {1, 2}, {2, 0}, {2, 3}, {3, 4}, {0, 5}};
    int n = 6;

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
    vector<int> AP(n, 0);

    for(int i = 0; i<n; i++){
        if(!visited[i]){
            dfs(i, -1, adj, visited, tin, low, 0, AP);
        }
    }

    for(int i = 0; i<n; i++){
        if(AP[i] == 1){
            cout << i << " ";
        }
    }
}