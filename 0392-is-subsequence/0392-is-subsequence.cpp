class Solution {
public:
    bool isSubsequence(string s, string t) {
        //base case
        if (s.empty()) return true; 
        if (t.empty()) return false;

        //recursive step
        if (s[0] == t[0]) {
            return isSubsequence(s.substr(1), t.substr(1));
        } else {
            return isSubsequence(s, t.substr(1));
        }
    }
};