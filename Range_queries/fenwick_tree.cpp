struct Fenwick {
    int n;
    vector<ll> bit;

    Fenwick(vector<ll>& a) : n(a.size()), bit(n + 1, 0) {
        for(int i = 1; i <= n; i++) {
            bit[i] += a[i - 1];
            int j = i + (i & -i);
            if(j <= n) bit[j] += bit[i];
        }
    }

    void add(int idx, ll val) {
        for(idx++; idx <= n; idx += idx & -idx)
            bit[idx] += val;
    }

    ll query(int idx) {
        ll ans = 0;
        for(idx++; idx > 0; idx -= idx & -idx)
            ans += bit[idx];
        return ans;
    }

    ll query(int l, int r) {
        return query(r) - (l ? query(l - 1) : 0);
    }
};
