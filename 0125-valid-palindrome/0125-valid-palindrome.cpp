class Solution {
public:
    bool isPalindrome(string s) {
       string clean = "";
       
       for(char c : s) {
        if(isalpha(c)) {
            clean += tolower(c);
        } else if(isdigit(c)) {
            clean += c;
        }
       }

       int i = 0,  j = clean.size()-1;

       while(i < j) {
        if(clean[i] != clean[j]) {
            return false;
        }
        i++;
        j--;
       }

       return true;
    }
};