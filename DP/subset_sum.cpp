bool subset_sum(vector<int>& v, int S) {
    int n = v.size();
    vector<bool> dp(S + 1, false);

    dp[0] = true;

    for(int i = 0; i < n; i++) {
        for(int j = S; j >= v[i]; j--) {
            dp[j] = dp[j] || dp[j - v[i]];
        }
    }

    return dp[S];
}