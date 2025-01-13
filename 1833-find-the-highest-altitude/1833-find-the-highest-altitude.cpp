class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int maxSeen = 0, size = gain.size(), curr = 0;

        for(int i = 0; i < size; i++) {
            curr+=gain[i];
            maxSeen = max(maxSeen, curr);
        }
        
        return maxSeen;
    }
};