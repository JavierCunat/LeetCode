class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int size = nums.size(), zeros = 0, maxSeen = 0, j = 0;

        for(int i = 0; i < size; i++) {
            if(nums[i] == 0) {
                zeros++;
            }

            while(zeros > 1) {
                if(nums[j] == 0) {
                    zeros--;
                }
                j++;
            }

            maxSeen = max(maxSeen, i - j + 1);
        }

        return maxSeen-1;
    }
};