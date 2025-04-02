class Solution {
public:
    int numTilings(int n) {
        const int MOD = 1e9 + 7;
        //find the recurring relation between the domino and tromino for the input n
        //write down pattern and make sequence which here is An = 2An-1 + An-3 
        vector<long> dp(n+2, 0);
        dp[0] = 1;
        dp[1] = 2;
        dp[2] = 5;

        for(int i = 3; i <= n; i++) {
            dp[i] = (dp[i - 1] * 2 + dp[i - 3]) % MOD;
        }

        return dp[n-1];
    }
};