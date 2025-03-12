class Solution {
public:
    //reviewed on 3/11/2025

    bool validPalindrome(string s) {
        return validPalindrome(s, 0, s.size()-1, false);
    }

    bool validPalindrome(string s, int i, int j, bool val) {
        while(i <= j) {
            if(s[i] == s[j]) {
                i++;
                j--;
            } else {
                if(val) {
                    return false;
                } else {
                    return
                    validPalindrome(s, i + 1, j, true) || 
                    validPalindrome(s, i, j - 1, true);
                }   
            }
        }
        return true;
    }


};
