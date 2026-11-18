struct Fenwick {
    vector<ll> bit;
    Fenwick(int n) : bit(n + 1) {}
    void add(int i, ll v) { 
        for(++i; i < bit.size(); i += i & -i) bit[i] += v; 
    }
    ll query(int i) { 
        ll s = 0; for(++i; i; i -= i & -i) s += bit[i]; return s; 
    }
};
