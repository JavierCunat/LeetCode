class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        using MinPQ = priority_queue<int, vector<int>, greater<int>>;
        int n = costs.size();
        long long res = 0;

        MinPQ left, right;
        int i = 0; 
        int j = n - 1; 

        // Preload up to `candidates` from each side without crossing.
        for (int c = 0; c < candidates && i <= j; ++c, ++i) left.push(costs[i]);
        for (int c = 0; c < candidates && j >= i; ++c, --j) right.push(costs[j]);

        while (k--) {
            int s1 = left.empty()  ? INT_MAX : left.top();
            int s2 = right.empty() ? INT_MAX : right.top();

            if (s1 <= s2) {
                res += s1;
                left.pop();
                // Refill from the left if there are unpushed elements left
                if (i <= j) {
                    left.push(costs[i]);
                    ++i;
                }
            } else {
                res += s2;
                right.pop();
                // Refill from the right if there are unpushed elements left
                if (i <= j) {
                    right.push(costs[j]);
                    --j;
                }
            }
        }
        return res;
    }
};