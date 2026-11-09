int longest_window(ll k, vector<ll>& v) {
    int n = v.size();
    int l = 0, best = 0;
    ll sum = 0;

    for(int r = 0; r < n; r++) {
        sum += v[r];

        while(l <= r && sum > k) {
            sum -= v[l];
            l++;
        }

        best = max(best, r - l + 1);
    }

    return best;
}