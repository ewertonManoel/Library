vector<int> bipartite(int n, vector<vector<int>>& adj) {
    vector<int> color(n, -1);

    for(int s = 0; s < n; s++) {
        if(color[s] != -1) continue;

        queue<int> q;
        q.push(s);
        color[s] = 0;

        while(!q.empty()) {
            int u = q.front();
            q.pop();

            for(int v : adj[u]) {
                if(color[v] == -1) {
                    color[v] = color[u] ^ 1;
                    q.push(v);
                }
                else if(color[v] == color[u]) {
                    return {};
                }
            }
        }
    }

    return color;
}
