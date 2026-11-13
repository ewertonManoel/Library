int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};

vector<pii> flood_fill(int r, int c, vector<string>& grid, vector<vector<bool>>& visited) {
    int n = grid.size(), m = grid[0].size();
    vector<pii> group;
    queue<pii> q;

    char target = grid[r][c];

    visited[r][c] = true;
    q.push({r, c});

    while(!q.empty()) {
        auto [r, c] = q.front();
        q.pop();

        group.push_back({r, c});

        for(int i = 0; i < 4; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];

            if(nr < 0 || nr >= n || nc < 0 || nc >= m) continue;
            if(visited[nr][nc] || grid[nr][nc] != target) continue;

            visited[nr][nc] = true;
            q.push({nr, nc});
        }
    }

    return group;
}
