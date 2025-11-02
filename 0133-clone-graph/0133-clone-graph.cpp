/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:

    Node* dfs(Node* node, unordered_map<int, Node*>& visited) {
        if(visited.count(node->val)) return visited[node->val];
        Node* clone = new Node(node->val);
        visited[node->val] = clone;

        for(Node* neighbor : node->neighbors) {
            if(!visited.count(neighbor->val)) dfs(neighbor, visited);
            clone->neighbors.push_back(visited[neighbor->val]);
        }

        return clone;
    }

    Node* cloneGraph(Node* node) {
        if(!node) return node;
        
        unordered_map<int, Node*> visited;

        return dfs(node, visited);
    }
};