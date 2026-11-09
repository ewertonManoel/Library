vector<int> toposort(vector<vector<int>>& adj) {
    int n = adj.size();
    vector<int> indegree(n, 0);
    vector<int> order;
    queue<int> q;

    for(int u = 0; u < n; u++) {
        for(int v : adj[u]) {
            indegree[v]++;
        }
    }

    for(int i = 0; i < n; i++) {
        if(indegree[i] == 0) q.push(i);
    }

    while(!q.empty()) {
        int u = q.front();
        q.pop();

        order.push_back(u);

        for(int v : adj[u]) {
            indegree[v]--;

            if(indegree[v] == 0) q.push(v);
        }
    }

    if(order.size() != n) return {};

    return order;
}