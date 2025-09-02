class Solution {
public:
    bool isSubsequence(string s, string t) {
        //reviewed on 09/02/2025
        int i = 0, j = 0; //pointers for each string
        int sSize = s.size(), tSize = t.size();

        while(i < sSize && j < tSize) {
            if(s[i] == t[j]) {
                i++;
            }
            j++;
        }

        return i == sSize;
    }
};
