class Solution {
public:
//optimization removed visisted set reducing time complexity and space used
    void dfs(int row, int col, int &count, int &rows, int &cols, vector<vector<char>>& grid) {
        if(row < 0 || col < 0 || row >= rows || col >= cols || grid[row][col] != '1') return;
        //mark visited by changing grid to a v
        grid[row][col] = 'v';

        //check adjacent chars and perform dfs on them to capture the entire island
       
        dfs(row - 1, col, count, rows, cols, grid); //up
        dfs(row + 1, col, count, rows, cols, grid); //down
        dfs(row, col - 1, count, rows, cols, grid); //left
        dfs(row, col + 1, count, rows, cols, grid); //right
        
    }

    int numIslands(vector<vector<char>>& grid) {
        //go DFS everytime we find a 1 and mark 1's as visited in a visited set map of x,y if we can form an island add to counter
        int rows = grid.size();
        int cols = grid[0].size();
        int count = 0;
        vector<vector<bool>> visited;

        for(int row = 0; row < rows; row++) {
            for(int col = 0; col < cols; col++) {
                if(grid[row][col] == '1') {
                    dfs(row, col, count, rows, cols, grid);
                    count++;
                }
            }
        }

        return count;
    }
};