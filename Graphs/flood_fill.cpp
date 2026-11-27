void flood_fill(int r, int c, vector<string>& grid, vector<vector<bool>>& visited) {
    int dr[4] = {-1, 1, 0, 0};
    int dc[4] = {0, 0, -1, 1};
    
    int n = grid.size(), m = grid[0].size();
    if(r < 0 || r >= n || c < 0 || c >= m) return;
    if(visited[r][c] || grid[r][c] == '#') return;

    queue<pii> q;
    visited[r][c] = true;
    q.push({r, c});

    while(!q.empty()) {
        auto [cr, cc] = q.front(); q.pop();
        for(int i = 0; i < 4; i++) {
            int nr = cr + dr[i];
            int nc = cc + dc[i];
            if(nr < 0 || nr >= n || nc < 0 || nc >= m) continue;
            if(visited[nr][nc] || grid[nr][nc] == '#') continue;
            visited[nr][nc] = true;
            q.push({nr, nc});
        }
    }
}
