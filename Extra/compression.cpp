vector<int> compress(vector<int>& v) {
    vector<int> vals = v, ans(v.size(), 0);
    sort(vals.begin(), vals.end());
    vals.erase(unique(vals.begin(), vals.end()), vals.end());

    for(int i = 0; i < v.size(); i++) {
        ans[i] = lower_bound(vals.begin(), vals.end(), v[i]) - vals.begin();
    }
    return ans;
}
