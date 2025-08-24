class Solution {
public:
    int minDistance(string word1, string word2) {
        int word1Size = word1.length();
        int word2Size = word2.length();

        vector<vector<int>> dp(word1Size + 1, vector<int>(word2Size + 1, 0));

        //base cases
        for(int i = 0; i <= word1Size; i++) dp[i][0] = i;
        for(int j = 0; j <= word2Size; j++) dp[0][j] = j;


        for(int i = 1; i <= word1Size; i++) {
            for(int j = 1; j <= word2Size; j++) {
                if(word1[i-1] == word2[j-1]) {
                    dp[i][j] = dp[i-1][j-1];
                } else {
                    dp[i][j] = 1 + min({
                        dp[i][j-1], //insert
                        dp[i-1][j], //delete
                        dp[i-1][j-1] //replace
                    });
                }
            }
        }

        return dp[word1Size][word2Size];
    }
};