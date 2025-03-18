class Solution {
public:
//reviewed on 3/16/2025
//did this in C in cs107 :D not as nice looking
    int strStr(string haystack, string needle) {
        if(haystack.size() < needle.size()) {
            return -1;
        }
        
        for(int i = 0; i <= haystack.size() - needle.size(); i++) {
            if(haystack.substr(i, needle.size()) == needle) {
                return i;
            }
        }
        return -1;
    }
};
