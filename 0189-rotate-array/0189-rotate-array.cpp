class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        if(k > n) {
            k = k % n; //a full k rotation is just put back to original order
        }

        vector<int> res(n, 0);
        for(int i = 0; i < n; i++) {
            res[ (i+k) % n] = nums[i];
        }
        
        nums = res;
    
    }
};