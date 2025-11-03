class Solution {
public:

    static const int DIRS[4][2];

    static void dfs(
        vector<vector<int>>& heights, vector<vector<int>>& arr,
        int x, int y, int r, int c
        ) {
        if(arr[x][y]) return;
        arr[x][y] = 1;

        for(const auto& dir : DIRS) {
            int nx = x + dir[0];
            int ny = y + dir[1];

            if(nx >= 0 && ny >= 0 && nx < r && ny < c && heights[nx][ny] >= heights[x][y]) {
                dfs(heights, arr, nx, ny, r, c);
            }
        }
        
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        //two searchs starting from the pacific ocean edges and other atlantic ocean edges
        //compare which we marked as reachable from both and the common ones are the ans
        int r = heights.size();
        int c = heights[0].size();

        if(c == 0 || r == 0) return {};

        vector<vector<int>> pac(r, vector<int>(c, 0));
        vector<vector<int>> atl(r, vector<int>(c, 0));

        for (int j = 0; j < c; ++j) dfs(heights, pac, 0, j, r, c); //top
        for (int i = 0; i < r; ++i) dfs(heights, pac, i, 0, r, c); //left

        for (int j = 0; j < c; ++j) dfs(heights, atl, r-1, j, r , c); //bottom
        for (int i = 0; i < r; ++i) dfs(heights, atl, i, c-1, r, c); //right

        vector<vector<int>> res;

        for(int i = 0; i < r; i++) {
            for(int j = 0; j < c; j++) {
                if(pac[i][j] == 1 && atl[i][j] == 1) {
                    res.push_back({i, j});
                }
            }
        }

        return res;
    }
};

const int Solution::DIRS[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};