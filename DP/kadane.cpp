int n;
vector<ll> v;
vector<vector<ll>> dp;

ll solve(int i, bool started) {
    if (i == n) return started ? 0 : -INF;
    if (dp[i][started] != -1) return dp[i][started];

    ll take = v[i] + solve(i + 1, 1);
    if (!started) {
        ll skip = solve(i + 1, started);
        return dp[i][started] = max(take, skip);
    } 
    else {
        ll stop = 0;
        return dp[i][started] = max(take, stop);
    }
}
