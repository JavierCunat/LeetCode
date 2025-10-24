class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        //bfs through path keep visisted set to avoid cycles
        int path = 1;
        int directions[][2] = {{1,0}, {0,1}, {-1,0}, {0,-1}, {1,1}, {-1,-1}, {1,-1}, {-1,1}};
        queue<pair<int,int>> q;
        int rowSize = grid.size(), colSize = grid[0].size();
        if(grid[0][0] != 0) return -1;
        q.push({0, 0});
        grid[0][0] = 2; 

        while(!q.empty()) {
            int s = q.size();

            for(int k = 0; k < s; k++) {
                pair<int,int> cur =  q.front(); q.pop();
                if(cur.first == grid.size()-1 && cur.second == grid[0].size()-1) return path;
                for(auto& dir : directions) {
                    int newR = cur.first + dir[0];
                    int newC = cur.second + dir[1];
                    if(newR >= 0 && newC >= 0 && newR < rowSize && newC < colSize && grid[newR][newC] == 0) {
                        q.push({newR, newC});
                        grid[newR][newC] = 2; //make 2 as visited
                    }
                }
            }
            path++;
        }


        return -1;
    }
};