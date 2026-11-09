void floyd_warshall(vector<vector<ll>>& dist) {
    int n = dist.size();
    const ll INF = 1e18;

    for(int k = 0; k < n; k++) {
        for(int i = 0; i < n; i++) {
            if(dist[i][k] == INF) continue;

            for(int j = 0; j < n; j++) {
                if(dist[k][j] == INF) continue;

                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
}