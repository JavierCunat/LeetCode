class Solution {
public:
    void dfs(
        int row, int col, map<pair<int,int>, bool> &visited, int &count, int &rows, int &cols, vector<vector<char>>& grid
        ) {
        if(visited[{row, col}] == true || grid[row][col] == '0') return;
        //mark visited
        visited[{row, col}] = true;

        //check adjacent chars and perform dfs on them to capture the entire island
        if(row != 0 && !visited[{row - 1, col}]) {
            dfs(row - 1, col, visited, count, rows, cols, grid);
        }

        if(row != rows-1 && !visited[{row + 1, col}]) {
            dfs(row + 1, col, visited, count, rows, cols, grid);
        }

        if(col != 0 && !visited[{row, col-1}]) {
            dfs(row, col - 1, visited, count, rows, cols, grid);
        }

        if(col != cols - 1 && !visited[{row, col + 1}]) {
            dfs(row, col + 1, visited, count, rows, cols, grid);
        }

        
    }

    int numIslands(vector<vector<char>>& grid) {
        //go DFS everytime we find a 1 and mark 1's as visited in a visited set map of x,y if we can form an island add to counter
        int rows = grid.size();
        int cols = grid[0].size();
        int count = 0;
        map<pair<int,int>, bool> visited;

        for(int row = 0; row < rows; row++) {
            for(int col = 0; col < cols; col++) {
                if(grid[row][col] == '1' && !visited[{row, col}]) {
                    dfs(row, col, visited, count, rows, cols, grid);
                    count++;
                }
            }
        }

        return count;
    }
};