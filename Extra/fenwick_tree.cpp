struct Fenwick {
    vector<ll> bit;
    Fenwick(int n) : bit(n + 1) {}
    Fenwick(vector<ll>& a) : Fenwick(a.size()) { 
        for(int i = 0; i < a.size(); i++) add(i, a[i]); 
    }
    void add(int i, ll v) { 
        for(++i; i < bit.size(); i += i & -i) bit[i] += v; 
    }
    ll query(int i) { 
        ll s = 0; for(++i; i; i -= i & -i) s += bit[i]; return s; 
    }
};
