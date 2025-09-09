class Solution {
public:
    int singleNumber(vector<int>& nums) {
        //reviewed 09/08/2025
        size_t size = nums.size();
        int prev = 0;
        for(int i = 0; i < size; i++) {
            prev ^= nums[i];
        }

        return prev;
    }
};
