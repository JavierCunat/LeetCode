class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        //check for cycle only way it is impossible to finish the classes is if there's a cycle

        //kahns algo
        //add all nodes with no dependencies (in-degree) to the queue then get rid of the edges
        //graph will cycle with have (in-dgree) greater than one
        vector<int> indegree(numCourses, 0); //keep track of indegree per node with index being node
        vector<vector<int>> adj(numCourses); //directed node to edge
        for(auto& prereq : prerequisites) {
            adj[prereq[1]].push_back(prereq[0]);
            indegree[prereq[0]]++;
        }

        queue<int> q;
        for(int i = 0; i < numCourses; i++) {
            if(indegree[i] == 0) q.push(i);
        }

        int visited = 0;
        while(!q.empty()) {
            int node = q.front(); q.pop();
            visited++;
            for(auto neighbor : adj[node]) {
                indegree[neighbor]--; //symbolically removing edge
                if(indegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }


        return numCourses == visited;
    }
};