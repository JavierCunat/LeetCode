class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        //optimized to 
        unordered_map<int, int> occurrences;

        for(int n : arr) {
            occurrences[n]++;
        }

        unordered_set<int> set;

        for(const auto& pair : occurrences) { //can also just do auto x : occurences
            set.insert(pair.second);
        }

        return occurrences.size() == set.size(); //if the set has a smaller size than occurences that means there was two of the same occurences in the map and should return false
    }
};