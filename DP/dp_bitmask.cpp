vector<ll> bitmask_dp(int n) {
    vector<ll> dp(1 << n, INF);

    dp[0] = 0;

    for(int mask = 0; mask < (1 << n); mask++) {
        for(int i = 0; i < n; i++) {
            if(mask & (1 << i)) continue;

            int new_mask = mask | (1 << i);

            dp[new_mask] = min(dp[new_mask], dp[mask] + cost[mask][i]);
        }
    }

    return dp;
}