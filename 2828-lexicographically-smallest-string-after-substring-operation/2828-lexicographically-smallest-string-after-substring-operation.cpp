class Solution {
public:
    string smallestString(string s) {
    int n = s.size();
    bool changed = false;

    for (int i = 0; i < n; ++i) {
        if (s[i] == 'a' && !changed) continue; //skip leading 'a's

        //decrement as soon as we find non-'a'
        while (i < n && s[i] != 'a') {
            s[i] = (s[i] - 'a' - 1 + 26) % 26 + 'a'; // decrement with wrap
            changed = true;
            i++;
        }

        if (changed) break; //only one substring allowed
    }

    //Edge case: all 'a's → change the last one to 'z'
    if (!changed) s[n - 1] = 'z';

    return s;
    }
};