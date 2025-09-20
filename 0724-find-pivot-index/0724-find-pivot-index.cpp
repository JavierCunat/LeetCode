class Solution {
public:
    int pivotIndex(vector<int>& nums) {
       int sum = accumulate(nums.begin(), nums.end(), 0);
       int left = 0;

       for(int i = 0; i < nums.size(); i++) {
        left+=nums[i];
        if(left == sum) return i;
        sum-=nums[i];
       }

       return -1;
    }
};