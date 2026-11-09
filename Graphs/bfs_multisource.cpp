vector<int> bfs(vector<int>& sources, vector<vector<int>>& adj) {
    int n = adj.size();
    vector<int> dist(n, -1);
    queue<int> q;

    for(int s : sources) {
        if(dist[s] != -1) continue;

        dist[s] = 0;
        q.push(s);
    }

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