using edge = tuple<ll, int, int>;

pair<ll, vector<edge>> kruskal(int n, vector<edge>& edges) {
    sort(edges.begin(), edges.end());
    DSU dsu(n);
    ll cost = 0;
    vector<edge> mst;

    for (auto [w, u, v] : edges) {
        if (dsu.unite(u, v)) {
            cost += w;
            mst.push_back({w, u, v});
        }
    }
    return {cost, mst};
}
