class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int size = nums.size();
        vector<int> res(size, 1);
        int product = 1;

        //left cumulative product
        for(int i = 0; i < size; i++) {
            res[i] = product;
            product *= nums[i];
        }

        //right cumulative product
        product = 1;
        for(int i = size-1; i >= 0; i--) {
            res[i] *= product;
            product*= nums[i];
        }

        return res;
    }
};