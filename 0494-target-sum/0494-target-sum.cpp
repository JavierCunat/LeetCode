class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        vector<vector<int>> dp(nums.size()+1, vector<int>(2 * sum + 1, 0));

        if(abs(target) > sum) return 0;

        //there is 1 way to sum to 0 (sum is 0 since we are going to 2 * sum)
        dp[0][sum] = 1;

        for(int i = 1; i <= nums.size(); i++) {
            for(int j = 0; j <= sum*2; j++) {
                if(j - nums[i-1] >= 0) {
                    dp[i][j] += dp[i-1][j - nums[i-1]];
                }
                if(j + nums[i-1] <= sum * 2) {
                    dp[i][j] += dp[i-1][j + nums[i-1]];
                }
            }
        }

        return dp[nums.size()][target + sum];
    }
};