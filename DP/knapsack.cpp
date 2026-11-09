ll knapsack(int cap, vector<pair<int, ll>>& v) {
    int n = v.size();
    vector<ll> dp(cap + 1, 0);

    for(auto [w, val] : v) {
        for(int j = cap; j >= w; j--) {
            dp[j] = max(dp[j], dp[j - w] + val);
        }
    }

    return dp[cap];
}