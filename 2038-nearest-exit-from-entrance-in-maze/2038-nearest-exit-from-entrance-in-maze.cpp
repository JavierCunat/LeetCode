class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        //shortest path algo using BFS with queue step one direction each time until find first exit
        queue<vector<int>> q;
        set<pair<int,int>> visited;
        int steps = 0;
        int rowSize = maze.size(), colSize = maze[0].size();
        q.push(entrance);
        visited.insert({entrance[0], entrance[1]});


        while(!q.empty()) {
            int size = q.size();
            while(size--) {
                vector<int> curr = q.front(); q.pop();

                if(maze[curr[0]][curr[1]] == '.' && 
                curr != entrance &&
                (curr[0] == 0 || curr[0] == rowSize-1 || curr[1] == 0 || curr[1] == colSize-1) 
                ) return steps;

                //check up
                if(curr[0] > 0 && !visited.count({curr[0] - 1, curr[1]}) && maze[curr[0]-1][curr[1]] == '.') {
                    q.push({curr[0]-1, curr[1]});
                    visited.insert({curr[0]-1, curr[1]});
                }
                
                //check left
                if(curr[1] > 0 && !visited.count({curr[0], curr[1] - 1})  && maze[curr[0]][curr[1]-1] == '.') {
                    q.push({curr[0], curr[1]-1});
                    visited.insert({curr[0], curr[1]-1});
                }

                //check down
                if(curr[0] < rowSize-1 && !visited.count({curr[0]+1, curr[1]}) && maze[curr[0]+1][curr[1]] == '.' ){
                    q.push({curr[0] + 1, curr[1]});
                    visited.insert({curr[0] + 1, curr[1]});
                }

                //check right
                if(curr[1] < colSize-1 && !visited.count({curr[0], curr[1]+1}) && maze[curr[0]][curr[1]+1] == '.' ){
                    q.push({curr[0], curr[1] + 1});
                    visited.insert({curr[0], curr[1] + 1});
                }
            }
            steps++;
        }

        return -1;
    }
};