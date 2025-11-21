class Solution {
public:
    int robLinear(int l, int r, vector<int>& nums) {
        int prev2 = 0;
        int prev1 = 0;

        for(int i = l; i <= r; i++) {
            int pick = prev2 + nums[i];
            int skip = prev1;
            int curr = max(pick, skip);
            prev2 = prev1;
            prev1 = curr;
        }

        return prev1;
    }

    int rob(vector<int>& nums) {
        int size = nums.size();
        if(size == 0) return 0;
        if(size == 1) return nums[0];
        if(size == 2) return max(nums[0], nums[1]);

        //two cases we use the first house or we use the last house
        int case1 = robLinear(0, size-2, nums); //exclude last
        int case2 = robLinear(1, size-1, nums); //exclude first

        return max(case1, case2);
    }
};