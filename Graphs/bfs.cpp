vector<int> bfs(int src, vector<vector<int>>& adj) {
    int n = adj.size();
    vector<int> dist(n, -1);
    queue<int> q;

    dist[src] = 0;
    q.push(src);

    while(!q.empty()) {
        int u = q.front();
        q.pop();

        for(int v : adj[u]) {
            if(dist[v] != -1) continue;

            dist[v] = dist[u] + 1;
            q.push(v);
        }
    }

    return dist;
}