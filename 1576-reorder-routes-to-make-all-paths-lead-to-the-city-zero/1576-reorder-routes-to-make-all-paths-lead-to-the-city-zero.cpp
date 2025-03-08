class Solution {
public:

    int changes = 0;
    void dfs(int node, int parent, vector<vector<pair<int,int>>>& adj) {
        for(auto& [neighbor, sign] : adj[node]) {
            if(neighbor != parent) {
                changes += sign;
                dfs(neighbor, node, adj);
            }
        }
    }


    int minReorder(int n, vector<vector<int>>& connections) {
        //dfs approach if need to switch nodes edges and go to the index of the node that we just switched to make sure we can get to 0
        //change picture like a bin tree with root node being 0
        vector<vector<pair<int,int>>> adj(n);
        for(auto& connection : connections) {
            adj[connection[0]].push_back({connection[1], 1});
            adj[connection[1]].push_back({connection[0], 0});
        }
        dfs(0,-1, adj);
        return changes;        
    }
};