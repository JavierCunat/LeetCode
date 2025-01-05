class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int size = nums.size(), nonZeroIndex = 0;

        //move all non-zero indexs to front of array
        for(int i=0; i < size; i++) {
            if(nums[i] != 0) {
                nums[nonZeroIndex++] = nums[i];
            }
        }

        //fill rest of the array with 0's
        for(int i=nonZeroIndex; i < size; i++) {
            nums[i] = 0;
        }
    }
};