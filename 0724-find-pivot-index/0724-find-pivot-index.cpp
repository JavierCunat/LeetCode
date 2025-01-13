class Solution {
public:
    int pivotIndex(vector<int>& nums) {
       //optimized to O(n) by keeping a prefix sum of array
       int size = nums.size();
       int lhs = 0;
       int sum = accumulate(nums.begin(), nums.end(), 0);

       for(int i = 0; i < size; i++) {
        //check if leftsum equals rightsum
        if(lhs == sum-nums[i]-lhs) { return i; }
        lhs+=nums[i];
       }

       return -1;
    }
};