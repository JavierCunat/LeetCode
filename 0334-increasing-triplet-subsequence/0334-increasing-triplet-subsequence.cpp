class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        //reviewed 11/21/2025
        //brute force beats 46% in O(n) by storing the min (i), a flag bool and the prev var (j)
        //changed to use best approach by storing (i) min and (j) mid
        int size = nums.size();
        int i = INT_MAX, j = INT_MAX;

        for(int c = 0; c < size; c++) {
            if(i >= nums[c]) {
                i = nums[c];
            } else if(j >= nums[c]) {
                j = nums[c];
            } else {
                return true;
            }
        }

        return false;
    }
};
