class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        //two lines and faster? is it possible??
        nth_element(nums.begin(), nums.begin()+k-1, nums.end(), greater<int>());
        return nums[k-1];
    }
};