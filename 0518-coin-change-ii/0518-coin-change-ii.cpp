class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        sort(coins.begin(), coins.end());
        //rows are coins cols are amounts
        vector<vector<uint>> dp(n + 1, vector<uint>(amount+1, 0));

        for(int i = 0; i < n; i++) {
            dp[i][0] = 1;
        }

        for(int i = n-1; i >= 0; i--) {
            for(int j = 0; j <= amount; j++) {
                if(j >= coins[i]) {
                    dp[i][j] = dp[i+1][j];
                    dp[i][j] += dp[i][j - coins[i]];
                }
            }
        }

        return dp[0][amount];
    }
};