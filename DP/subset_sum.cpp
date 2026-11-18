bool subset_sum(vector<int>& v, int s) {
    int n = v.size();
    vector<bool> dp(s + 1, false);
    dp[0] = true;

    for(int i = 0; i < n; i++) {
        for(int j = s; j >= v[i]; j--) {
            dp[j] = dp[j] || dp[j - v[i]];
        }
    }
    return dp[s];
}
