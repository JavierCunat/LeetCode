class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        //reviewed 10/3/2025
        //shortest path algo using BFS with queue step one direction each time until find first exit
        //use in-place marking visited to reduce O(log n) time from using .count() and size/space of the set
        queue<vector<int>> q;
        int steps = 0;
        int rowSize = maze.size(), colSize = maze[0].size();
        q.push(entrance);
        maze[entrance[0]][entrance[1]] = 'v';


        while(!q.empty()) {
            int size = q.size();
            while(size--) {
                vector<int> curr = q.front(); q.pop();

                if(
                curr != entrance &&
                (curr[0] == 0 || curr[0] == rowSize-1 || curr[1] == 0 || curr[1] == colSize-1) 
                ) return steps;

                //check up
                if(curr[0] > 0 && maze[curr[0]-1][curr[1]] == '.') {
                    q.push({curr[0]-1, curr[1]});
                    maze[curr[0]-1][curr[1]] = 'v';
                }
                
                //check left
                if(curr[1] > 0 && maze[curr[0]][curr[1]-1] == '.') {
                    q.push({curr[0], curr[1]-1});
                    maze[curr[0]][curr[1]-1] = 'v';
                }

                //check down
                if(curr[0] < rowSize-1 && maze[curr[0]+1][curr[1]] == '.' ){
                    q.push({curr[0] + 1, curr[1]});
                    maze[curr[0]+1][curr[1]] = 'v';
                }

                //check right
                if(curr[1] < colSize-1 && maze[curr[0]][curr[1]+1] == '.' ){
                    q.push({curr[0], curr[1] + 1});
                    maze[curr[0]][curr[1] + 1] = 'v';
                }
            }
            steps++;
        }

        return -1;
    }
};
