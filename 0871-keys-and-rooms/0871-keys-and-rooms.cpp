class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        //reviewed on 9/13/2025
        //dfs approach that is simple
        int n = rooms.size();
        stack<int> stack;
        vector<bool> visited(n, 0);
        visited[0] = 1;

        for(auto i : rooms[0]) stack.push(i);

        while(!stack.empty()) {
            int key = stack.top();
            stack.pop();
            if(visited[key]) continue;
            for(auto i : rooms[key]) stack.push(i);
            visited[key] = 1;
        }

        for(int i = 0; i < n; i++) {
            if(visited[i] == 0) return false;
        }

        return true;
    }
};
