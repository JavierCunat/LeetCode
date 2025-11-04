class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        int size = s.length();
        unordered_set<char> set;

        int best = 0, j = 0;

        for(int i = 0; i < size; i++) {
            while(set.count(s[i])) {
                set.erase(s[j++]);
            }
            set.insert(s[i]);
            best = max(best, i - j + 1);
        }

        return best;
    }
};