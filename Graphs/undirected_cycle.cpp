bool has_cycle_dfs(int u, int p, vector<bool>& visited, vector<vector<int>>& adj) {
    visited[u] = true;

    for(int v : adj[u]) {
        if(v == p) continue;

        if(!visited[v]) {
            if(has_cycle_dfs(v, u, visited, adj)) return true;
        }
        else {
            return true;
        }
    }

    return false;
}

bool has_cycle(vector<vector<int>>& adj) {
    int n = adj.size();
    vector<bool> visited(n, false);

    for(int i = 0; i < n; i++) {
        if(!visited[i]) {
            if(has_cycle_dfs(i, -1, visited, adj)) return true;
        }
    }

    return false;
}
