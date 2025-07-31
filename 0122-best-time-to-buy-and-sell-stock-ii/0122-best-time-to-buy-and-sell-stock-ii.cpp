class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        int prev = prices[0];
        int size = prices.size();

        //greedy approach sell whenever theres a profit
        for(int i = 1; i < size; i++) {
            if(prices[i] > prev) {
                profit += prices[i] - prev;
            }
            prev = prices[i];
        }

        return profit;
    }
};