class Solution {
public:

    static bool colorNode(int u, int color, vector<vector<int>>& graph, vector<int>& colors) {
        colors[u] = color;

        for(auto& neighbor : graph[u]) {
            if(colors[neighbor] == -1) {
                if(!colorNode(neighbor, color ^ 1, graph, colors)) return false;
            } else if(colors[neighbor] == color) {
                return false;
            }
        }

        return true;
    }


    bool isBipartite(vector<vector<int>>& graph) {
        //start at aribtrary node explore its neighbors and make them a color
        //color each node different if there is a node same color that are neighbors return false
        int n = graph.size();
        vector<int> colors(n, -1);

        //do every node because may be disconnected components
        for(int i = 0; i < n; i++) {
            if(colors[i] != -1) continue;
            if(!colorNode(i, 0, graph, colors)) {
                return false;
            }

        }        

        return true;
    }
};