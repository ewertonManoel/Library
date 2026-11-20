struct SegTree {
    ll NEUTRAL = 0;
    int n; vector<ll> st;
    SegTree(int n = 0) : n(n), st(4 * n, NEUTRAL) {}
    SegTree(vector<ll>& a) : SegTree(a.size()) {build(a, 1, 0, n - 1);}

    ll merge(ll a, ll b) { return a + b; }

    void build(vector<ll>& a, int p, int l, int r) {
        if (l == r) { st[p] = a[l]; return; }
        int m = l + (r - l) / 2;
        build(a, p * 2, l, m); build(a, p * 2 + 1, m + 1, r);
        st[p] = merge(st[p * 2], st[p * 2 + 1]);
    }

    void update(int idx, ll val, int p = 1, int l = 0, int r = -1) {
        if (r == -1) r = n - 1;
        if (l == r) { st[p] = val; return; }
        int m = l + (r - l) / 2;
        idx <= m ? update(idx, val, p * 2, l, m) : update(idx, val, p * 2 + 1, m + 1, r);
        st[p] = merge(st[p * 2], st[p * 2 + 1]);
    }

    ll query(int ql, int qr, int p = 1, int l = 0, int r = -1) {
        if (r == -1) r = n - 1;
        if (r < ql || l > qr) return NEUTRAL;
        if (ql <= l && r <= qr) return st[p];
        int m = l + (r - l) / 2;
        return merge(query(ql, qr, p * 2, l, m), query(ql, qr, p * 2 + 1, m + 1, r));
    }
};
