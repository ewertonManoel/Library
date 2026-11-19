struct Fenwick {
    vector<ll> bit;
    Fenwick(int n) : bit(n) {}
    void add(int i, ll v) {for(; i < bit.size(); i |= i + 1) bit[i] += v;}
    ll query(int i) {ll s = 0; for(; i >= 0; i = (i & (i + 1)) - 1) s += bit[i]; return s;}
};
