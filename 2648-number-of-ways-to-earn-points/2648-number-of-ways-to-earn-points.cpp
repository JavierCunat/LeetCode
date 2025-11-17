class Solution {
public:
    int waysToReachTarget(int target, vector<vector<int>>& types) {
        //bounded knapsack
        const int MOD = 1e9 + 7;
        int m = types.size();

        vector<vector<int>> dp(m + 1, vector<int>(target + 1, 0)); //num of ways to score points solving some questions of the first i types
        dp[0][0] = 1; //0 types 0 points 1 way

        for(int i = 1; i <= m; i++) {
            int count = types[i-1][0]; //max num of questions of this type
            int marks = types[i-1][1]; //num points per question

            for(int s = 0; s <= target; s++) {
                long long ways = 0;
                //try taking up to k question
                for(int k = 0; k <= count; k++) {
                    int prev = s - k * marks;
                    if(prev < 0) break;
                    ways += dp[i-1][prev];
                    if (ways >= MOD) ways -= MOD;
                }
                dp[i][s] = ways;
            }
        }

        return dp[m][target];
    }
};