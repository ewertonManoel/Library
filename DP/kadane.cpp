int n;
vector<ll> v;
vector<vector<ll>> dp;
vector<vector<bool>> vis;

ll solve(int i, bool started) {
    if (i == n) return started ? 0 : -INF;
    if (vis[i][started]) return dp[i][started];
    vis[i][started] = true;

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

ll kadane(vector<ll>& a) {
    v = a;
    n = v.size();
    dp.assign(n, vector<ll>(2, 0));
    vis.assign(n, vector<bool>(2, false));
    return solve(0, 0);
}
