class Solution {
public:


double dfs(const string& curr, const string& target,
            unordered_map<string, unordered_map<string, double>>& graph,
            unordered_set<string>& visited, double product) {
        
        if (graph.find(curr) == graph.end()) return -1.0;
        if (curr == target) return product;

        visited.insert(curr);

        for (auto& neighbor : graph[curr]) {
            if (visited.count(neighbor.first)) continue;
            double result = dfs(neighbor.first, target, graph, visited, product * neighbor.second);
            if (result != -1.0) return result;
        }

        return -1.0;
        }
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {


        unordered_map<string, unordered_map<string, double>> graph;
        for (int i = 0; i < equations.size(); i++) {
            string A = equations[i][0];
            string B = equations[i][1];
            double val = values[i];
            graph[A][B] = val;          // A / B = val
            graph[B][A] = 1.0 / val;    // B / A = 1/val
        }


        vector<double> res;
        for (auto& query : queries) {
            string A = query[0], B = query[1];
            if (!graph.count(A) || !graph.count(B)) {
                res.push_back(-1.0);
            } else if (A == B) {
                res.push_back(1.0);
            } else {
                unordered_set<string> visited;
                double result = dfs(A, B, graph, visited, 1.0);
                res.push_back(result);
            }
        }

        return res;
    }
};