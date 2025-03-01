class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int size = piles.size();
        int lowest = 1, highest = *max_element(piles.begin(), piles.end());
        int k = highest;

        while(lowest < highest) {
            int mid = (highest - lowest) / 2 + lowest;
            int hours = 0;

            for(int i = 0; i < size; i++) {
                if(hours > h) break;
                hours += (piles[i] + mid - 1) / mid;  //equivalent to ceil(piles[i] / mid)
            }
            if(hours <= h) {
                k = mid;
                highest = mid;
            } else {
                lowest = mid+1;
            }

        } 
        
        return k;
    }
};