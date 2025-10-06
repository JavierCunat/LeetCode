class Solution {
public:
    int bfs(vector<vector<int>>& grid, int& i, int& j) {
     int n = grid.size(), m = grid[0].size();

    static const int dr[4] = {1, -1, 0, 0};
    static const int dc[4] = {0, 0, 1, -1};

    queue<pair<int,int>> q;
    q.push({i, j});
    grid[i][j] = 0;
    int res = 1;

    while (!q.empty()) {
        auto [r, c] = q.front(); q.pop();
        for (int k = 0; k < 4; ++k) {
            int nr = r + dr[k], nc = c + dc[k];
            if (nr >= 0 && nr < n && nc >= 0 && nc < m && grid[nr][nc] == 1) {
                grid[nr][nc] = 0;
                q.push({nr, nc});
                ++res;
            }
        }
    }
    return res;
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int area = 0;

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 1) {
                    area = max(area, bfs(grid, i, j));
                }
            }
        }

        return area;
    }
};