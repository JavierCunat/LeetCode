class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        //first graph problem solved :))) took a bit
        int index = 0;
        unordered_set<int> keys = {0};
        unordered_set<int> visited;
        queue<int> q;
        q.push(0);

        while(!q.empty()) {
            while(visited.count(q.front()) > 0) q.pop(); //make sure we don't end in a cycle
            int size = q.size();

            for(int i = 0; i < size; i++) {
                int curr = q.front();
                visited.insert(curr);
                q.pop();

                for(int key : rooms[curr]) {
                    keys.insert(key);
                    q.push(key);
                }

            }
        }
        

        return keys.size() == rooms.size();
    }
};