using edge = tuple<ll, int, int>;

pair<vector<ll>, bool> bellman_ford(int src, int n, vector<edge>& edges) {
    vector<ll> dist(n, INF);
    dist[src] = 0;

    for(int i = 0; i < n - 1; i++) {
        bool changed = false;
        for(auto [w, u, v] : edges) {
            if(dist[u] == INF) continue;
            if(dist[u] + w < dist[v]) {
                dist[v] = max(-INF, dist[u] + w);
                changed = true;
            }
        }
        if(!changed) break;
    }

    bool has_neg_cycle = false;
    for(int i = 0; i < n; i++) {
        bool changed = false;
        for(auto [w, u, v] : edges) {
            if(dist[u] == INF) continue;
            if(dist[u] == -INF || dist[u] + w < dist[v]) {
                if(dist[v] != -INF) {
                    dist[v] = -INF;
                    changed = true;
                    has_neg_cycle = true;
                }
            }
        }
        if(!changed) break;
    }
    return {dist, has_neg_cycle};
}
