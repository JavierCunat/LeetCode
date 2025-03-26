class Solution {
public:
    double dfs(
        const string& curr, const string& target, unordered_map<string, unordered_map<string, double>>& graph, unordered_set<string>& visited, double product
    ) {
        if(graph.find(curr) == graph.end()) return -1;
        if(curr == target) return product;
        visited.insert(curr);
        for(auto& neighbor : graph[curr]) {
            if(visited.count(neighbor.first)) continue;
            double result = dfs(neighbor.first, target, graph, visited, product * neighbor.second);
            if (result != -1.0) return result;
        }
        return -1.0;
    }

    vector<double> calcEquation(
        vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries
    ) {
       //we should treat problem as nodes with weights as their values
       int eqSize = equations.size();
       vector<double> res;

       unordered_map<string, unordered_map<string, double>> graph;//adj list {a : {b : 2.0, c : 3.0} }
       for(int i = 0; i < eqSize; i++) {
        string charA = equations[i][0];
        string charB = equations[i][1];
        double val = values[i];

        graph[charA][charB] = val;
        graph[charB][charA] = 1.0 / val;
       }

       for(vector<string> query : queries) {
        string A = query[0], B = query[1];
        if(!graph.count(A) || !graph.count(B)) {
            res.push_back(-1.0);
        } else {
            unordered_set<string> visited;
            double result = dfs(A, B, graph, visited, 1.0);
            res.push_back(result);
        }
       }

       return res;                                          
    }
};