class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> occurrences;
        unordered_set<int> set;

        for(int n : arr) {
            occurrences[n]++;
        }

        for(const auto& pair : occurrences) {
            if(set.count(pair.second) > 0) {
                return false;
            } else {
                set.insert(pair.second);
            }
        }

        return true;
    }
};