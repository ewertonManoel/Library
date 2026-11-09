void dfs(int u, vector<vector<int>>& adj, vector<bool>& visited, vector<int>& order) {
    visited[u] = true;
    order.push_back(u);

    for(int v : adj[u]) {
        if(visited[v]) continue;
        dfs(v, adj, visited, order);
    }
}