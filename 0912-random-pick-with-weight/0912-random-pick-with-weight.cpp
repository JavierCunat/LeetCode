#include <random>

class Solution {
private:
    vector<int> prefix;
    std::mt19937 rng{std::random_device{}()};
    uniform_int_distribution<int> dist;
public:
    Solution(vector<int>& w) {
        prefix.resize(w.size());
        partial_sum(w.begin(), w.end(), prefix.begin());
        int total = prefix.back();
        dist = uniform_int_distribution<int>(1, total);
    }
    
    int pickIndex() {
        int x = dist(rng);
        return lower_bound(prefix.begin(), prefix.end(), x) - prefix.begin();
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */