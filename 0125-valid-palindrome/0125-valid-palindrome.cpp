class Solution {
public:
    bool isPalindrome(string s) {
        string v = "";

        for(int i = 0; i < s.size(); i++) {
            if(isalnum(s[i])) {
                v+=tolower(s[i]);
            }
        }

        int i = 0;
        int j = v.size() -1;

        while(i <= j) {
            if(v[i] == v[j]) {
                i++;
                j--;
            } else {
                return false;
            }
        }

        return true;
    }
};