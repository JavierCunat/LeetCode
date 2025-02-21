class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        //can do regular binsearch even though not fully sorted when there is a peak that part is sorted
        int left = 0, right = nums.size()-1;
        while(left < right) {
            long mid = left + (right-left) / 2;
            if(nums[mid] < nums[mid+1]) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }

        return left;
    }
};