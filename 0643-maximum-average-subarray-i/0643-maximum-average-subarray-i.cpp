class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        //reviewed 12/17/2025
        //best approach O(n) with two seperate for loops using sliding window and max method
        int size = nums.size();
        int curSum = 0;

        for(int i = 0; i < k; i++) {
            curSum+=nums[i];
        }

        int maxSum = curSum;

        for(int i = k; i < size; i++) {
            curSum+= nums[i] - nums[i-k];
            maxSum = max(curSum, maxSum);
        }

        return static_cast<double>(maxSum) / k;
    }
};
