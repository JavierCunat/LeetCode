class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string res = "";
        long a = 0, b = 0;

        while(a < word1.size() && b < word2.size() ) {
            res+=word1[a];
            a++;
            res+=word2[b];
            b++;
        }

        while(a < word1.size()) {
            res+=word1[a];
            a++;
        }

        while(b < word2.size()) {
            res+=word2[b];
            b++;
        }

        return res;
    }
};