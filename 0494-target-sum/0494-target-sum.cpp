class Solution {
public:
    int backtrack(vector<int>& nums, int target, int index, long currSum) {
        if(index == nums.size()) {
            return (target == currSum) ? 1 : 0;
        }

        // add curr number and sub curr number
        return backtrack(nums, target, index + 1, currSum + nums[index]) + 
               backtrack(nums, target, index + 1, currSum - nums[index]);
    }


    int findTargetSumWays(vector<int>& nums, int target) {
        if(nums.empty()) return 0;
        return backtrack(nums, target, 0, 0);
    }
};