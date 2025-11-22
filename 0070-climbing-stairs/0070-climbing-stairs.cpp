class Solution {
public:
    int climbStairs(int n) {
        vector<int> dp(n+1, 0);
        //base cases
        dp[0] = 0; 
        if (n <= 1) return 1;
        dp[1] = 1;
        if (n == 2) return 2;
        dp[2] = 2;

        for(int i = 3; i <= n; i++) {
            dp[i] = dp[i-2] + dp[i-1]; //can climb one step or two at time
        }

        return dp[n];
    }
};