class Solution {
public:
    //Reviewed 4/10/2025
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
