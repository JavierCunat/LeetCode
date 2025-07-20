class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0) return false;
        string check = to_string(x);

        int i = 0, j = check.length()-1;
        while(i < j) {
            if(check[i++] != check[j--]) return false;
        }

        return true;
    }
};