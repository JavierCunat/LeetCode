class Solution {
public:
    int pivotIndex(vector<int>& nums) {
       //optimized to O(n) by keeping a prefix sum of array
       int size = nums.size();
       int sum = 0, lhs = 0;

       for(int num : nums) {
        sum+=num;
       }

       for(int i = 0; i < size; i++) {
        //check if leftsum equals rightsum
        if(lhs == sum-nums[i]-lhs) { return i; }
        lhs+=nums[i];
       }

       return -1;
    }
};