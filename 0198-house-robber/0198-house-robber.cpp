class Solution {
public:
    int rob(vector<int>& nums) {
        int maxAmount = 0;
        int size = nums.size();
        vector<int> dp(size + 1, 0);
        dp[0] = 0;
        dp[1] = nums[0];

        for(int i = 2; i < size+1; i++) {
            dp[i] = max(dp[i-1], dp[i-2] + nums[i-1]);
            //main decision either dont rob and stick with prev or rob this one nums[i] and prev-prev one
        }

        return dp[size];
    }
};