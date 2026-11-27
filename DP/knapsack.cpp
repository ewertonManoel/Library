ll knapsack(int cap, vector<pll>& items) {
    vector<ll> dp(cap + 1, 0);
    for(auto [w, v] : items) {
        for(int c = cap; c >= w; c--) {
            dp[c] = max(dp[c], dp[c - w] + v);
        }
    }
    return dp[cap];
}
