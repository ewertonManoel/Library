vector<vector<ll>> kadane(vector<ll>& v) {
    int n = v.size();
    vector<vector<ll>> dp(n + 1, vector<ll>(2, -INF));
    dp[n][0] = -INF;
    dp[n][1] = 0;

    for(int i = n - 1; i >= 0; i--) {
        dp[i][0] = max(v[i] + dp[i + 1][1], dp[i + 1][0]);
        dp[i][1] = max(v[i] + dp[i + 1][1], 0LL);
    }
    return dp;
}
