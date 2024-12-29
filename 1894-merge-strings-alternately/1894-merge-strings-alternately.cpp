class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        //optomized version
        string res = "";
        int a = 0, b = 0;
        int w1 = word1.size(), w2 = word2.size() ; //do this here instead of loop to not calculate many times
        res.reserve(w1+w2); //reserve space for res string ensures no repeated resizing/copying during concatination

        while(a < w1 && b < w2) {
            res+=word1[a++];
            res+=word2[b++];
        }

        //can do while loop similar to above but apparently append is faster!
        if(a < w1) {
            res.append(word1.begin() + a, word1.end());
        }
        if(b < w2) {
            res.append(word2.begin() + b, word2.end());
        }

        return res;
    }
};