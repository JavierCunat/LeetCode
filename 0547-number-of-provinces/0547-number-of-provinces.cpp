class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int cities = isConnected.size();
        int provinces = 0;
        stack<int> stack;
        vector<bool> visited(cities, 0);

        for(int i = 0; i < cities; i++) {
           if(!visited[i]) {
            provinces++;
            stack.push(i);

            while(!stack.empty()) {
                int index = stack.top();
                stack.pop();
                if(visited[index]) continue;
                visited[index] = true;

                for(int i = 0; i < cities; i++) {
                    if(isConnected[index][i] == 1 && !visited[i]) {
                        stack.push(i);
                    }
                }
            }
           }
        }


        return provinces;
    }
};