class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();

        //prune
        int total = accumulate(nums.begin(), nums.end(), 0);
        if(total % 2 != 0) return false;

        //build all possible subsets if a subset sum is equal to total/2 there is a way to split
        int target = total / 2;
        vector<char> dp(target + 1, 0);
        dp[0] = 1;  // sum 0 is always possible (empty subset)

        for(int x : nums) {
            for(int s = target; s >= x; s--) {
                //bool if it is possible to add up to that index
                dp[s] = dp[s] || dp[s - x];
            }
        }

        return dp[target]; //can we sum up to target with
    }
};