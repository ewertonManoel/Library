struct DSU {
    vector<int> parent, sz;

    DSU(int n) {
        parent.resize(n);
        sz.assign(n, 1);

        for(int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int find(int u) {
        if(parent[u] == u) return u;
        return parent[u] = find(parent[u]);
    }

    bool unite(int u, int v) {
        u = find(u);
        v = find(v);

        if(u == v) return false;

        if(sz[u] < sz[v]) swap(u, v);

        parent[v] = u;
        sz[u] += sz[v];

        return true;
    }

    bool same(int u, int v) {
        return find(u) == find(v);
    }

    int size(int u) {
        return sz[find(u)];
    }
};