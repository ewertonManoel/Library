using edge = tuple<ll, int, int>;

pair<ll, vector<edge>> kruskal(int n, vector<edge>& edges) {
    sort(edges.begin(), edges.end());

    DSU dsu(n);

    ll cost = 0;
    vector<edge> mst;

    for(auto [w, u, v] : edges) {
        if(!dsu.unite(u, v)) continue;

        cost += w;
        mst.push_back({w, u, v});

        if(mst.size() == n - 1) break;
    }

    return {cost, mst};
}