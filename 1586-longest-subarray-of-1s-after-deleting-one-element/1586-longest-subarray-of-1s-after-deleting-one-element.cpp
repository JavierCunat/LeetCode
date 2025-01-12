class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int size = nums.size(), zeros = 0, maxSeen = 0, j = 0;

        for(int i = 0; i < size; i++) {
            zeros += (nums[i] == 0); //this is neat way of saying if(nums[0]== 0) zero++

            while(zeros > 1) {
                zeros -= (nums[j] == 0);
                j++;
            }

            maxSeen = max(maxSeen, i - j);
        }

        return maxSeen;
    }
};