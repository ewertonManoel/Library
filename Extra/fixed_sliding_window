ll max_window_sum(vector<ll>& v, int k) {
    int n = v.size();

    if(k <= 0 || k > n) return 0;

    ll sum = 0, best = LLONG_MIN;

    for(int i = 0; i < n; i++) {
        sum += v[i];

        if(i >= k) sum -= v[i - k];

        if(i >= k - 1) {
            best = max(best, sum);
        }
    }

    return best;
}