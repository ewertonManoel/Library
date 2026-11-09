using edge = tuple<ll, int, int>;

pair<vector<ll>, bool> bellman_ford(int src, int n, vector<edge>& edges) {
    const ll INF = 1e18;
    vector<ll> dist(n, INF);

    dist[src] = 0;

    for(int i = 0; i < n - 1; i++) {
        bool changed = false;

        for(auto [w, u, v] : edges) {
            if(dist[u] == INF) continue;

            if(dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                changed = true;
            }
        }

        if(!changed) break;
    }

    for(auto [w, u, v] : edges) {
        if(dist[u] == INF) continue;

        if(dist[u] + w < dist[v]) {
            return {dist, true};
        }
    }

    return {dist, false};
}