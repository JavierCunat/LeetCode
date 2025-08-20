class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        //reviewed on 8/19/2025
        //intuition use bfs to mark rotten oranges and track minute, do a final check to see if all rotten
        int rows = grid.size();
        int cols = grid[0].size();
        int minutes = 0;
        int fresh = 0;
        queue<pair<int,int>> q;

        //find rotten to spread... if there are several they start rotting at same time so we fill the queue with all initially rotten oranges this is called multi-source BFS
        for(int i = 0; i < rows; i++) {
            for(int j= 0; j < cols; j++) {
                if(grid[i][j] == 2) q.push({i, j});
                else if (grid[i][j] == 1) fresh++;
            }
        }

        while(!q.empty()) {
            int size = q.size();
            bool change = false;
            while(size--) {
                pair<int,int> curr = q.front(); q.pop();
                if(grid[curr.first][curr.second] == 0) continue;
                grid[curr.first][curr.second] = 3;

                //check 4-directionally ajacent add them to q
                //let 3 be visisted and rotten so we dont have to use a visited set
                if(curr.first > 0 && grid[curr.first-1][curr.second] == 1) { //up
                    grid[curr.first-1][curr.second] = 3; fresh--;
                    q.push({curr.first-1, curr.second});
                    change = true;
                }

                if(curr.second > 0 && grid[curr.first][curr.second-1] == 1) { //left
                    grid[curr.first][curr.second-1] = 3; fresh--;
                    q.push({curr.first, curr.second-1});
                    change = true;
                }

                if(curr.first < rows-1 && grid[curr.first+1][curr.second] == 1) { //down
                    grid[curr.first+1][curr.second] = 3; fresh--;
                    q.push({curr.first+1, curr.second});
                    change = true;
                }

                if(curr.second < cols-1 && grid[curr.first][curr.second+1] == 1) { //right
                    grid[curr.first][curr.second+1] = 3; fresh--;
                    q.push({curr.first, curr.second+1});
                    change = true;
                }
            }
            if(change) minutes++;
        }

        return (fresh != 0) ? -1 : minutes;
    }
};
