class Solution {
public:
    string minWindow(string s, string t) {
        int sLen = s.size(), tLen = t.size();
        if(tLen > sLen) return "";

        //set sliding window start everytime we see new char in s from t
        //from here if we didn't find it in curr window we just start again in that window?  WRONG
        //OR do one pass and set index of each time we see differnet new char from t in s and use those?

        vector<int> requiredCount(128, 0);
        for(char c : t) requiredCount[c]++;

        int charsStillNeeded = tLen;
        int windowStart = 0;
        int bestWindowStart = 0;
        int bestWindowLength = INT_MAX;

        for(int windowEnd = 0; windowEnd < sLen; windowEnd++) {
            char endChar = s[windowEnd];
            if(requiredCount[endChar] > 0) {
                charsStillNeeded--;
            }

            requiredCount[endChar]--;

            while(charsStillNeeded == 0) {
                int currentLength = windowEnd - windowStart + 1;
                if(currentLength < bestWindowLength) {
                    bestWindowLength = currentLength;
                    bestWindowStart = windowStart;
                }

                char startChar = s[windowStart];
                requiredCount[startChar]++;
                if(requiredCount[startChar] > 0) {
                    charsStillNeeded++;
                }

                windowStart++;
            }
        }

        return (bestWindowLength == INT_MAX) ? "" : s.substr(bestWindowStart, bestWindowLength);
        
    }
};