class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        //best approach O(n) with two seperate for loops using sliding window and max method
        int size = nums.size();
        double curSum = 0;

        for(int i = 0; i < k; i++) {
            curSum+=nums[i];
        }

        double maxSum = curSum;

        for(int i = k; i < size; i++) {
            curSum+= nums[i] - nums[i-k];
            maxSum = max(curSum, maxSum);
        }

        return maxSum / k;
    }
};