class Solution {
public:
    int singleNumber(vector<int>& nums) {
        size_t size = nums.size();
        int prev = 0;
        for(int i = 0; i < size; i++) {
            prev ^= nums[i];
        }

        return prev;
    }
};