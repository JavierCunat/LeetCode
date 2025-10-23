class Solution {
public:
    static vector<int> binSearch(vector<int>& nums, int target, int high, int low) {
        if(low > high) return {-1, -1};
        int mid = low + (high - low) / 2;

        if(nums[mid] == target) {
            int L = mid, R = mid;
            while(L > 0 && nums[L-1] == target) {
                L--;
            }

            while(R + 1 < nums.size() && nums[R+1] == target) {
                R++;
            }

            return{L, R};
        }

        if(nums[mid] > target) return binSearch(nums, target, mid-1, low);
        else return binSearch(nums, target, high, mid+1);
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        //binary search then linear
        if(nums.empty()) return {-1, -1};
        return binSearch(nums, target, nums.size()-1, 0);
    }
};