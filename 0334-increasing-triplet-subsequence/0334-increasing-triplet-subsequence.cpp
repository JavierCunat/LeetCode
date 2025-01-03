class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int size = nums.size();
        bool flag = false;
        int prev;
        int min = INT_MAX;

        for(int i = 0; i < size-1; i++) {
            if(nums[i] < min) {
                min = nums[i];
            }

            if(min < nums[i+1]) {
                if(flag && prev < nums[i+1]) {
                    return true;
                }
                flag = true;
                prev = nums[i+1];
            }
        }

        return false;
    }
};