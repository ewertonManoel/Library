bool dfs(int u, int p, vector<bool>& vis, vector<vector<int>>& adj) {
    vis[u] = true;
    for (int v : adj[u]) {
        if (v == p) continue;
        if (vis[v] || dfs(v, u, vis, adj)) return true;
    }
    return false;
}

bool has_cycle(vector<vector<int>>& adj) {
    int n = adj.size();
    vector<bool> vis(n, false);
    for (int i = 0; i < n; i++) {
        if (!vis[i] && dfs(i, -1, vis, adj)) return true;
    }
    return false;
}
