class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int res = 0;
        int prefix = 0;
        unordered_map<int, int> freq;
        freq[0] = 1; //base case

        for(int num : nums) {
            prefix += num;
            auto iterator = freq.find(prefix - k); //if prefix - k exist means we must have had a # that summed to k
            if(iterator != freq.end() ) res += iterator->second;
            freq[prefix]++;
        }

        return res;
    }
};