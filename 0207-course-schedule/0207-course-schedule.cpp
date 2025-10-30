class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        //khans algo to find topological sorting of graph
        //put everything into adj list vertex -> other vertex
        //track the number of indegrees and start at the node with indegree of 0, then delete that edge and repeat
        int n = prerequisites.size(), m = prerequisites.size();
        vector<vector<int>> adj(numCourses);
        vector<int> indegrees(numCourses, 0);
        int visited = 0;

        for(int i = 0; i < n; i++) {
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
            indegrees[prerequisites[i][0]]++;
        }

        queue<int> q;
        for(int i = 0; i < numCourses; i++) {
            if(indegrees[i] == 0) q.push(i);
        }
        

        while(!q.empty()) {
            int node = q.front(); q.pop();
            visited++;
            
            for(auto neighbor : adj[node]) {
                indegrees[neighbor]--;
                if(indegrees[neighbor] == 0) q.push(neighbor);
            }

        }

        return visited == numCourses;





    }
};