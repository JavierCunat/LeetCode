class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
    //review  11/14/25
    int i = 0, j = 0;

    while (i < str1.size() && j < str2.size()) {
        if (str1[i] == str2[j] || 
            (str1[i] + 1 == str2[j]) || 
            (str1[i] == 'z' && str2[j] == 'a')) {
            j++;
        }
        if(j == str2.size()) { return true; }
        i++;
    }

    return j == str2.size();
    }
};
