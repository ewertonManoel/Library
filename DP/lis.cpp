vector<ll> get_lis(vector<ll>& v) {
    int n = v.size();
    vector<ll> dp;
    vector<int> id, parent(n, -1);

    for(int i = 0; i < n; i++) {
        int pos = lower_bound(dp.begin(), dp.end(), v[i]) - dp.begin();

        if(pos > 0) parent[i] = id[pos - 1];

        if(pos == dp.size()) {
            dp.push_back(v[i]);
            id.push_back(i);
        }
        else {
            dp[pos] = v[i];
            id[pos] = i;
        }
    }

    vector<ll> ans;
    int cur = id.back();

    while(cur != -1) {
        ans.push_back(v[cur]);
        cur = parent[cur];
    }

    reverse(ans.begin(), ans.end());
    return ans;
}