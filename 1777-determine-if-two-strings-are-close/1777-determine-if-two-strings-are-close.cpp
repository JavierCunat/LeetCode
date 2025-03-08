class Solution {
public:
    //reviewed on 3/7/2025
    /**
    Intuition: Put each word into an unordered map with their freq. Then as long as a one map can be matched with  the other maps value's we should return true
    **/
    bool closeStrings(string word1, string word2) {
        int w1 = word1.size(), w2 = word2.size();
        if(w1 != w2) return false;

        unordered_map<char, int> map1;
        unordered_map<char, int> map2;
        vector<int> vec;

        for(int i = 0; i < w1; i++) {
            map1[word1[i]]++;
            map2[word2[i]]++;
        }

        
        //go through each map key and make sure we have a another key with that same value
        for(auto& x : map1) {
            if(map2.count(x.first) == 0) { return false; }
        }

        unordered_map<int, int> checker;

        for(auto& x : map1) {
            checker[x.second]++;
        }

        for(auto& x : map2) {
            checker[x.second]--;
        }

        for(auto& x : checker) {
            if(x.second != 0) { return false; }
        }

        return true;
    }
};
