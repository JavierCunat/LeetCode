class Solution {
public:

    template <class InBounds>
    static void dfs(vector<vector<char>>& board, int i, int j, int r, int c, InBounds&& inbounds) {
        
        int dir[4][2] = { {0,1}, {1, 0}, {-1, 0}, {0, -1} };

        for(auto d : dir) {
            int nr = i + d[0];
            int nc = j + d[1];

            if(inbounds(nr, nc, r, c)) {
                board[nr][nc] = 'S';
                dfs(board, nr, nc, r, c, inbounds);
            }
        }

    }

    void solve(vector<vector<char>>& board) {
        //find all island and fill with 'X' if not touching edge
        //for all 'O' find not on edge run bfs on them and cover the area

        int r = board.size();
        int c = board[0].size();

        auto inbounds = [&](int i, int j, int r, int c) -> bool {
            return ( 
                i >= 0 && j >= 0 && i < r && j < c &&
                board[i][j] == 'O' 
            );
        };

        //from the boarders mark all connected 'O' as safe
        for(int i = 0; i < r; i++) {
            if(board[i][0] == 'O') {board[i][0] = 'S'; dfs(board, i, 0, r, c, inbounds);}
            if(board[i][c-1] == 'O') {board[i][c-1] = 'S'; dfs(board, i, c-1, r, c, inbounds);}
        }

        for(int j = 0; j < c; j++) {
            if(board[0][j] == 'O') {board[0][j] = 'S'; dfs(board, 0, j, r, c, inbounds); }
            if(board[r-1][j] == 'O') {board[r-1][j] = 'S'; dfs(board, r-1, j, r, c, inbounds); }
        }


        for(int i = 0; i < r; i++) {
            for(int j = 0; j < c; j++) {
               if(board[i][j] == 'O') board[i][j] = 'X';
               else if(board[i][j] == 'S') board[i][j] = 'O';
            }
        }
    }
};