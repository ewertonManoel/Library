int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

vector<pii> flood_fill(int r, int c, vector<string>& grid, vector<vector<bool>>& visited) {
    int n = grid.size(), m = grid[0].size();
    vector<pii> group;
    queue<pii> q;

    char target = grid[r][c];

    visited[r][c] = true;
    q.push({r, c});

    while(!q.empty()) {
        auto [x, y] = q.front();
        q.pop();

        group.push_back({x, y});

        for(int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if(visited[nx][ny] || grid[nx][ny] != target) continue;

            visited[nx][ny] = true;
            q.push({nx, ny});
        }
    }

    return group;
}