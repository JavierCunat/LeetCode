class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int size = nums.size(), res = 0, sum = 0;
        unordered_map<int, int> prefixSum;
        prefixSum[0] = 1;

        //prefix sums (p1 - p2) % k == 0 means subarray between is divisble by k 
        for(int num : nums) {
            sum += num;
            int mod = ((sum % k) + k) % k; //handle negatives
            res+=prefixSum[mod];
            prefixSum[mod]++;
        }
    
        return res;
    }
};