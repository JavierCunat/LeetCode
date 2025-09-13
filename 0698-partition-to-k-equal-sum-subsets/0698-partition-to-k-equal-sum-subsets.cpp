class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        //0/1 knapsack with bitmasking
        long long total = accumulate(nums.begin(), nums.end(), 0);
        if(total % k) return false;

        int n = nums.size();
        int target = total / k;
        sort(nums.begin(), nums.end(), greater<int>());
        if(nums[0] > target) return false;

        int N = 1 << n;
        vector<int> dp(N, -1);
        dp[0] = 0;

        for(int mask = 0; mask < N; mask++) {
            if(dp[mask] == -1) continue;

            for(int i = 0; i < n; i++) { //try to add unused item
                if(mask & (1 << i)) continue;

                int nextSum = dp[mask] + nums[i];
                if(nextSum > target) continue;

                int nextMask = mask | (1 << i);
                // Store remainder: if bucket filled, reset to 0
                dp[nextMask] = nextSum % target;
            }

        }

        return dp[N - 1] == 0;
    }
};