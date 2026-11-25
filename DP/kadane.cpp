int n;
vector<int> v;
vector<vector<int>> dp;

int solve(int i, bool started) {
    if (i == n) return started ? 0 : -INF;
    if (dp[i][started] != -1) return dp[i][started];

    int take = v[i] + solve(i + 1, 1);
    if (!started) {
        int skip = solve(i + 1, started);
        return dp[i][started] = max(take, skip);
    } 
    else {
        int stop = 0;
        return dp[i][started] = max(take, stop);
    }
}
