class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
         //use max_element method to find the max in the array, then just make sure the i^th elem is bigger than or equal to this when added extraCandies to it
         //thought about sorting to make it faster but I think it would be hard since we have to build an res array with the corresponding positions in its correct place
        int max = *max_element(candies.begin(), candies.end());
        vector<bool> res(candies.size());

        for(int i = 0; i < candies.size(); i++) {
            if(candies[i] + extraCandies >= max) {
                res[i] = true;
            }
        }
        
        return res;
    }
};