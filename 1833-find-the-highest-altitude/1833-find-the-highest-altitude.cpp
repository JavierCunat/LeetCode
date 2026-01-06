class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        //reviewed 1/5/2026
        int maxSeen = 0, size = gain.size(), curr = 0;

        for(int i = 0; i < size; i++) {
            curr+=gain[i];
            maxSeen = max(maxSeen, curr);
        }
        
        return maxSeen;
    }
};
