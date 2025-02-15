class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        //use binary search on potions array once we find the one that the spell to potion strength is greater than success we can get the length-i to be in the pairs result
        vector<int> pairs;
        size_t numSpells = spells.size();
        size_t numPotions = potions.size();
        sort(potions.begin(), potions.end());
        
        for(size_t i = 0; i < numSpells; i++) {
            long long start = 0, end = numPotions-1;
            int firstValidIndex = numPotions;
            
            while(start <= end) {
                long long mid = (end-start)/2 + start;
                if((long long)spells[i] * potions[mid] >= success) {
                    firstValidIndex = mid;
                    end = mid - 1;
                } else {
                    start = mid + 1;
                }
            }

            pairs.push_back(numPotions-firstValidIndex);
        }

        return pairs;
    }
};