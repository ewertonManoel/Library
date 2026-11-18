struct DSU {
    vector<int> p, sz;
    DSU(int n) : p(n), sz(n, 1) {iota(p.begin(), p.end(), 0);}

    int find(int u) {return p[u] == u ? u : p[u] = find(p[u]);}
    bool unite(int u, int v) {
        if ((u = find(u)) == (v = find(v))) return false;
        if (sz[u] < sz[v]) swap(u, v);
        return p[v] = u, sz[u] += sz[v], true;
    }
};
