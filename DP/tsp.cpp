ll tsp(vector<vector<ll>>& dist) {
    int n = dist.size();
    if(n == 0) return 0;
    vector<vector<ll>> dp(1 << n, vector<ll>(n, INF));
    dp[1][0] = 0;

    for(int mask = 1; mask < (1 << n); mask++) {
        for(int u = 0; u < n; u++) {
            if(dp[mask][u] == INF) continue;
            for(int v = 0; v < n; v++) {
                if((mask & (1 << v)) || dist[u][v] == INF) continue;
                int nmask = mask | (1 << v);
                dp[nmask][v] = min(dp[nmask][v], dp[mask][u] + dist[u][v]);
            }
        }
    }

    ll ans = INF;
    int full = (1 << n) - 1;
    for(int u = 0; u < n; u++) {
        if(dp[full][u] == INF || dist[u][0] == INF) continue;
        ans = min(ans, dp[full][u] + dist[u][0]);
    }
    return ans;
}
