class Solution {
public:
    void rotate(vector<int>& nums, int k) {
       int n = nums.size();
        if (n == 0) return;
        k %= n;
        if (k == 0) return;

        // helper lambda to reverse a range in place
        auto rev = [&](int l, int r) {
            while (l < r) {
                swap(nums[l], nums[r]);
                ++l;
                --r;
            }
        };

        //reverse entire array
        rev(0, n - 1);
        //reverse first k elements
        rev(0, k - 1);
        //reverse the rest
        rev(k, n - 1);
    }
};