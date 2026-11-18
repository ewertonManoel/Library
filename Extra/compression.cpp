vector<int> compress(vector<int>& v) {
    vector<int> ans(v.size(), 0), vals = v;
    sort(vals.begin(), vals.end());
    vals.erase(unique(vals.begin(), vals.end()), vals.end());

    for(int i = 0; i < v.size(); i++) {
        ans[i] = lower_bound(vals.begin(), vals.end(), v[i]) - vals.begin();
    }
    return ans;
}
