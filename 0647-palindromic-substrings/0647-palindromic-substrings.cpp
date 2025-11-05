class Solution {
public:
    static int expand(const string& s, int L, int R) {
        int count = 0;

        while(L >= 0 && R < s.length() && s[L] == s[R]) {
            count++;
            L--;
            R++;
        }

        return count;
    }

    int countSubstrings(string s) {
        string curr = "";
        int res = 0;
        if(s.empty()) return 0;

        // abcd
        // abcd, ab, abc, bcd, cd
        // ab, abc, abcd, bc, bcd, cd,
        // O(n * (n-i) * (n-1)) //for entire string iterate get each substring check if palindrome

        //to not do that everytime do we store each indexs current substring? store true or flase if palidrome only change to true if we add char to back that same as front only change to false if its odd and we add a char that isn;t same as front

        for(int i = 0; i < s.length(); i++) {

            res += expand(s, i, i); //odd length palindrome centered at i
            res += expand(s, i, i + 1); //even length palindrom center at i, i+1
        }


        return res;

    }
};