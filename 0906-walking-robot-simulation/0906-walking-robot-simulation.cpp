class Solution {
public:

    struct PairHash {
    size_t operator()(const pair<int,int>& p) const noexcept {
        // simple combine
        return (static_cast<uint64_t>(static_cast<uint32_t>(p.first)) << 32)
             ^ static_cast<uint32_t>(p.second);
        }
    };


    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        int x = 0, y = 0;
        int best = 0;
        int dir = 0; //0 = 'N', 1 = 'E', 2 = 'S , 3 = 'W'
        int dx[4] = { 0, 1, 0, -1};
        int dy[4] = { 1, 0, -1, 0};
        unordered_set<pair<int,int>, PairHash> blocks;
        for(int i = 0; i < obstacles.size(); i++) blocks.insert({obstacles[i][0], obstacles[i][1]});

        for(int command : commands) {
            if(command == -2) {
                dir = (dir + 3) % 4;
            } else if(command == -1) {
                dir = (dir + 1) % 4;
            } else {
                for(int step = 0; step < command; step++) {
                    int nx = x + dx[dir];
                    int ny = y + dy[dir];
                    if(blocks.count({nx, ny})) break;
                    x = nx; y = ny;
                    best = max(x*x+y*y, best);
                }
            }
        }

        return best;
    }
};